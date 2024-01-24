/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:07:05 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/24 15:41:11 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_mutex_nb_philos(data);
	i = 0;
	data->start_time = ft_get_time();
	while (i++ < nb_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&ft_routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&ft_all_alive_routine, data))
		return (1);
	if (nb_meals_optional(data) == true
		&& pthread_create(&data->monit_all_full, NULL,
			&ft_all_full_routine, data))
		return (1);
	return (0);
}

/*
Con init_threads, creamos los hilos de los filosofos, el hilo que controla
que todos los filosofos esten vivos y el hilo que controla que todos los
filosofos hayan comido el numero de veces que se ha indicado.
*/

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_mutex_nb_philos(data);
	i = 0;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_optional(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (i++ < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}
/*
join_threads espera a que todos los hilos terminen.
*/

void	ft_free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_mutex_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}