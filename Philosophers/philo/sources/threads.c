/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:07:05 by agomez-m          #+#    #+#             */
/*   Updated: 2024/01/23 10:14:13 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = mutex_nb_philos(data);
	i = 0;
	data->start_time = get_time();
}