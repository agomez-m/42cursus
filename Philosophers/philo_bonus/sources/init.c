/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:19:55 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/22 11:43:39 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_philo	*philo_new(int id, t_data *data)
{
	t_philo	*p;

	p = malloc(sizeof(t_philo));
	if (!p)
		return (NULL);
	p->id = id;
	p->d = data;
	return (p);
}

void	philo_add(t_philo **p, t_philo *new)
{
	t_philo	*tmp;

	if (!*p)
	{
		*p = new;
		return ;
	}
	tmp = *p;
	while (tmp->id != new->id - 1)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = *p;
	(*p)->prev = new;
}

t_philo	*ft_philo_init(t_data *data)
{
	int		i;
	t_philo	*p;
	t_philo	*new;

	p = NULL;
	new = NULL;
	i = 0;
	while (++i <= data->n_philo)
	{
		new = philo_new(i, data);
		if (!new)
		{
			ft_philofree(p);
			datafree(data);
			return (NULL);
		}
		philo_add(&p, new);
	}
	return (p);
}

int	ft_run(t_philo *p)
{
	t_philo		*tmp;
	int			i;
	pthread_t	thread;

	tmp = p;
	i = p->d->n_philo;
	set_offset(p);
	while (i--)
	{
		tmp->pid = fork();
		if (tmp->pid == -1)
			return (1);
		else if (tmp->pid == 0)
		{
			if (pthread_create(&thread, NULL, &ft_monitor, tmp) != 0)
				return (1);
			if (pthread_detach(thread) != 0)
				return (1);
			exit(ft_routine(tmp));
		}
		else
			tmp = tmp->next;
	}
	return (0);
}

/* 	Con exit(philo_routine(tmp)) salimos del proceso hijo ejecutando su rutina 
	Con pthread_create(&thread, NULL, &monitor, tmp) creamos un hilo 
	que ejecuta la función monitor con el argumento tmp
	Con pthread_detach(thread) desvinculamos el hilo 
	creado con el proceso principal
*/

int	ft_sem_init(t_data *data)
{
	sem_unlink("forks");
	data->sem_forks = sem_open("forks", O_CREAT, 0644, data->n_philo);
	if (data->sem_forks == SEM_FAILED)
		return (1);
	sem_unlink("print");
	data->sem_print = sem_open("print", O_CREAT, 0644, 1);
	if (data->sem_print == SEM_FAILED)
		return (1);
	sem_unlink("death");
	data->sem_death = sem_open("death", O_CREAT, 0644, 1);
	if (data->sem_death == SEM_FAILED)
		return (1);
	sem_unlink("go");
	data->sem_go = sem_open("go", O_CREAT, 0644, data->n_philo / 2);
	if (data->sem_go == SEM_FAILED)
		return (1);
	sem_unlink("end");
	data->sem_end = sem_open("end", O_CREAT, 0644, 0);
	if (data->sem_end == SEM_FAILED)
		return (1);
	sem_unlink("time");
	data->sem_time = sem_open("time", O_CREAT, 0644, 1);
	if (data->sem_time == SEM_FAILED)
		return (1);
	return (0);
}

/*

"death": Este es el nombre del semáforo para identificarlos
O_CREAT: el semáforo debe ser creado si no existe. Si el semáforo ya existe,
esta bandera no tiene ningún efecto.
0644: permisos para el semáforo. 0644 especifica que el propietario 
tiene permisos de lectura y escritura, 
y que el grupo y otros tienen permisos de solo lectura.
1: indica que el recurso está disponible y puede ser 
utilizado por un solo proceso a la vez.

*/
