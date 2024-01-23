/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:41 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/23 12:34:05 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	ft_philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (get_time() - ge_mutex_last_eat_time(philo) > get_mutex_die_time(data)
		&& get_mutex_philo_state(philo) != EATING)
	{
		set_mutex_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}
