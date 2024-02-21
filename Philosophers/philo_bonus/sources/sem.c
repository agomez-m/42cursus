/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:25:57 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/06 12:15:12 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	set_philo_state(t_data *data, t_state state)
{
    sem_wait(data->philo.sem_philo);
    data->philo.state = state;
    sem_post(data->philo.sem_philo);
}

void	update_last_meal_time(t_data *data)
{
	sem_wait(data->philo.sem_philo);
	data->philo.last_eat_time = ft_get_time();
	sem_post(data->philo.sem_philo);
}

t_state	get_philo_state(t_data *data)
{
    t_state state;

	sem_wait(data->philo.sem_philo);
	state = data->philo.state;
	sem_post(data->philo.sem_philo);
	return (state);
}

uint64_t	get_last_eat_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->philo.sem_philo);
	time = data->philo.last_eat_time;
	sem_post(data->philo.sem_philo);
	return (time);
}
