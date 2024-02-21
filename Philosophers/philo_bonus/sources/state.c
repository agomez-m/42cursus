/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:41 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/06 14:10:47 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*monitor_death(void *args)
{
	t_data		*data;
	u_int64_t	time;

	data = (t_data *)args;
	data->philo.last_eat_time = data->start_time;
	while (1)
	{
		if (ft_get_time() > data->philo.last_eat_time + data->die_time)
		{
			time = ft_get_time() - data->start_time;
			sem_wait(data->philo.sem_philo);
			data->philo.is_dead = true;
			sem_post(data->philo.sem_philo);
			set_philo_state(data, DEAD);
			sem_wait(data->sem_print);
			printf("%llu philosopher %d is dead\n", time, data->philo.id);
			sem_post(data->sem_print);
			exit(0);
		}
		ft_usleep(5);
	}
}