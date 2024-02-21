/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleepthink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:19:38 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 13:14:19 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep(t_philo *philo)
{
	set_mutex_philo_state(philo, SLEEPING);
	if (get_mutex_philo_state(philo) == DEAD)
		return (1);
	ft_print_msg(philo->data, philo->id, SLEEP);
	ft_usleep(get_mutex_sleep_time(philo->data));
	return (0);
}

int	ft_think(t_philo *philo)
{
	set_mutex_philo_state(philo, THINKING);
	if (get_mutex_philo_state(philo) == DEAD)
		return (1);
	ft_print_msg(philo->data, philo->id, THINK);
	return (0);
}