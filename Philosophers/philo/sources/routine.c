/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:54:35 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/29 14:13:21 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	update_mutex_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_mutex_philo_state(philo) != DEAD)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (get_mutex_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_mutex_philo_state(philo) == DEAD)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}

void	*ft_all_alive_routine(void *data_p)
{
	int		i;
	int		nb_philos;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nb_philos = get_mutex_nb_philos(data);
	i = 0;
	while (get_mutex_keep_iter(data))
	{
		if (ft_philo_died(&philos[i]) && get_mutex_keep_iter(data))
		{
			ft_print_msg(data, philos[i].id, DIED);
			set_mutex_keep_iterating(data, false);
			ft_dead_all_philos(data);
			break ;
		}
		i = (i + 1) % nb_philos;
		usleep(1000);
	}
	return (NULL);
}

void	*ft_all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	i = -1;
	nb_philos = get_mutex_nb_philos(data);
	while (++i < nb_philos && get_mutex_keep_iter(data))
	{
		usleep(1000);
		if (ft_is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_mutex_keep_iter(data) == true)
	{
		set_mutex_keep_iterating(data, false);
		ft_dead_all_philos(data);
	}
	return (NULL);
}

/*
introducimos un retraso de 10ms para que los filosofos pares empiecen a comer
antes que los impares. Esto es para evitar que todos los filosofos intenten
coger el tenedor izquierdo al mismo tiempo.
*/