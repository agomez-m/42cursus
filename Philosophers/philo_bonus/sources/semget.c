/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semget.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:01:13 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/01 19:54:25 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

uint64_t	get_last_eat_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->philo.sem_philo);
	time = data->philo.last_eat_time;
	sem_post(data->philo.sem_philo);
	return (time);
}

t_state	get_philo_state(t_data *data)
{
	t_state	state;

	sem_wait(data->philo.sem_philo);
	state = data->philo.state;
	sem_post(data->philo.sem_philo);
	return (state);
}