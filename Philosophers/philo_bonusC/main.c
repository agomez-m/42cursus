/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:55:07 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 15:49:48 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#define NUM_FILOSOFOS 5
#define TIEMPO_MAXIMO_SIN_COMER_MICROSEGS 1000000 // 10 segundos en microsegundos

sem_t *comedor;
sem_t *tenedor[NUM_FILOSOFOS];
pthread_t threads[NUM_FILOSOFOS];
time_t ultima_comida[NUM_FILOSOFOS];
pthread_t tiempo_thread;
int filosofo_muerto[NUM_FILOSOFOS];
int programa_activo = 1;

void *filosofo(void *arg) {
    int id = *((int *) arg);
    int izq = id;
    int der = (id + 1) % NUM_FILOSOFOS;

    while (programa_activo) {
        printf("Filósofo %d pensando...\n", id);
        usleep(1000000); // Simula tiempo pensando
        time(&ultima_comida[id]);

        printf("Filósofo %d tiene hambre y quiere comer.\n", id);

        sem_wait(comedor);

        // Intenta adquirir los tenedores
        int intentos = 0;
        while (intentos < 5) { // Intenta 5 veces para evitar bloqueos
            if (sem_trywait(tenedor[izq]) == 0 && sem_trywait(tenedor[der]) == 0) {
                // Si se adquieren ambos tenedores, sale del bucle
                break;
            } else {
                // Si no se pueden adquirir ambos tenedores, libera el comedor y espera un poco
                sem_post(comedor);
                usleep(50000); // Espera 50 milisegundos
                sem_wait(comedor);
                intentos++;
            }
        }

        if (intentos == 5) {
            // Si después de 5 intentos no se pueden adquirir los tenedores, se sale de la función
            sem_post(comedor);
            pthread_exit(NULL);
        }

        if (!programa_activo) {
            sem_post(tenedor[der]);
            sem_post(tenedor[izq]);
            sem_post(comedor);
            pthread_exit(NULL);
        }

        printf("Filósofo %d está comiendo.\n", id);
        usleep(1000000); // Simula tiempo comiendo

        sem_post(tenedor[der]);
        sem_post(tenedor[izq]);
        sem_post(comedor);

        printf("Filósofo %d ha terminado de comer.\n", id);
    }
    pthread_exit(NULL);
}

void *control_tiempo(void *arg) {
    int i = 0;
    while (i < NUM_FILOSOFOS) {
        if (filosofo_muerto[i]) {
            pthread_cancel(threads[i]); // Cancelar el hilo del filósofo que ha muerto de hambre
            void *res;
            pthread_join(threads[i], &res); // Esperar a que el hilo muerto termine con un tiempo límite
            if (res == PTHREAD_CANCELED) {
                filosofo_muerto[i] = 0; // Restablecer el estado del filósofo muerto
                printf("Filósofo %d ha muerto de hambre.\n", i);
                programa_activo = 0; // Detener el programa
                break;
            } else {
                printf("Error: Filósofo %d no se ha detenido correctamente.\n", i);
            }
        }
        i++;
    }
    return NULL;
}

int main() {
    int ids[NUM_FILOSOFOS];
    int count = 0;

    comedor = sem_open("/comedor", O_CREAT, 0644, NUM_FILOSOFOS - 1);
    while (count < NUM_FILOSOFOS) {
        char nombre[20];
        sprintf(nombre, "/tenedor%d", count);
        tenedor[count] = sem_open(nombre, O_CREAT, 0644, 1);
        count++;
    }

    pthread_create(&tiempo_thread, NULL, control_tiempo, NULL);

    count = 0;
    while (count < NUM_FILOSOFOS) {
        ids[count] = count;
        pthread_create(&threads[count], NULL, filosofo, &ids[count]);
        count++;
    }

    count = 0;
    while (count < NUM_FILOSOFOS) {
        pthread_join(threads[count], NULL);
        count++;
    }

    sem_close(comedor);
    sem_unlink("/comedor");
    count = 0;
    while (count < NUM_FILOSOFOS) {
        char nombre[20];
        sprintf(nombre, "/tenedor%d", count);
        sem_close(tenedor[count]);
        sem_unlink(nombre);
        count++;
    }
	pthread_exit(NULL); 
    return 0;
}

