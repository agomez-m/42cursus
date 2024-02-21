/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:08 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/06 12:04:49 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	drop_forks(t_data *data)
{
	sem_post(data->sem_forks);
	sem_post(data->sem_forks);
	return (0);
}

bool	nb_meals_option_given(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

bool	philo_is_full(t_data *data)
{
	if (nb_meals_option_given(data) == false)
		return (false);
	if (data->nb_meals <= data->philo.nb_meals_had)
	{
		set_philo_state(data, FULL);
		return (true);
	}
	return (false);
}

int	take_forks(t_data *data)
{
	sem_wait(data->sem_forks);
	if (print_msg(data, TAKE_FORK))
	{
		sem_post(data->sem_forks);
		return (1);
	}
	if (data->nb_philos == 1)
		return (1);
	sem_wait(data->sem_forks);
	if (stop_if(get_philo_state(data)))
	{
		drop_forks(data);
		return (1);
	}
	if (print_msg(data, TAKE_FORK))
	{
		drop_forks(data);
		return (1);
	}

	return (0);
}

int	ft_eat(t_data *data)
{
	if (take_forks(data))
		return (1);
	set_philo_state(data, EATING);
	if (print_msg(data, EAT))
	{
		drop_forks(data);
		return (1);
	}
	ft_usleep(data->eat_time);
	update_last_meal_time(data);
	data->philo.nb_meals_had++;
	drop_forks(data);
	if (philo_is_full(data))
		return (1);
	return (0);
}
