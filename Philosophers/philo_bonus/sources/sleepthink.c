/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleepthink.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:19:38 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 17:52:40 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	ft_sleep(t_data *data)
{
	data->philo.state = SLEEPING;
	if (print_msg(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}

int	ft_think(t_data *data)
{
	if (print_msg(data, THINK))
		return (1);
	return (0);
}
