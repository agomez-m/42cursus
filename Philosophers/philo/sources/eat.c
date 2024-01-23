/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:40:08 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/23 12:14:33 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_left_fork(t_philo *philo)
{
	if (ft_philo_died(philo) || get_mutex_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_f);
	ft_print_msg(philo->data, philo->id, TAKE_FORK);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (ft_philo_died(philo) || get_mutex_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_f);
	ft_print_msg(philo->data, philo->id, TAKE_FORK);
	return (0);
}

int	ft_take_forks(t_philo *philo)
{
	if (get_mutex_nb_philos(philo->data) == 1)
		return (handle_1_philo(philo));
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}
	return (0);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

int	ft_eat(t_philo *philo)
{
	if (ft_take_forks(philo) != 0)
		return (1);
	set_mutex_philo_state(philo, EATING);
	ft_print_msg(philo->data, philo->id, EAT);
	update_mutex_last_meal_time(philo);
	ft_usleep(get_mutex_eat_time(philo->data));
	update_mutex_nb_meals_had(philo);
	ft_drop_forks(philo);
	return (0);
}