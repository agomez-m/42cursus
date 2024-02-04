/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:19:55 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 12:46:24 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	malloc_philsforksths(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
		return (free(data->philos), 1);
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
		return (free(data->philos), free(data->forks), 1);
	return (0);
}

/*
reservamos memoria para 
filosofos (t_philo),
tenedores (pthread_mutex_t) 
hilos (pthread_t).
*/

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t) ft_atoi(argv[2]);
	data->eat_time = (u_int64_t) ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t) ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	return (malloc_philsforksths(data));
}

/*
inicializamos la estructura data
datos de entrada del programa 
y los mutex que se van a usar.
*/

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = data->philos;
	while (i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_mutex_last_meal_time(&philos[i]);
		i += 1;
	}
	return (0);
}

/*
inicializamos la estructura philos
los datos de cada filosofo 
y los mutex que se van a usar.
*/

int	init_forks(t_data *data)
{
	int			i;
	t_philo		*philos;

	philos = data->philos;
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i += 1;
	}
	i = 1;
	philos[0].left_f = &data->forks[0];
	philos[0].right_f = &data->forks[data->nb_philos - 1];
	while (i < data->nb_philos)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
		i += 1;
	}
	return (0);
}

/*
inicializamos los mutex de los tenedores
lY asignamos a cada filosofo sus tenedores.
*/
