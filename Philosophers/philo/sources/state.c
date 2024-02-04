/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:09:41 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/30 17:13:32 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	ft_philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (ft_get_time() - get_mutex_last_eat_time(philo) \
		> get_mutex_die_time(data) && get_mutex_philo_state(philo) != EATING)
	{
		set_mutex_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}

bool	ft_is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_mutex_nb_meals_philo_had(philo) >= data->nb_meals)
		result = true;
	return (result);
}

void	ft_dead_all_philos(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	nb_philos = get_mutex_nb_philos(data);
	philos = data->philos;
	i = -1;
	while (++i < nb_philos)
		set_mutex_philo_state(&philos[i], DEAD);
}