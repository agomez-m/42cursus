/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:04:12 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/22 11:42:44 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

u_int64_t	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

/*convertimos el tiempo actual a milisegundos y lo devolvemos. gettimeofday()
nos da el tiempo en segundos y microsegundos, por lo que lo convertimos a
milisegundos.*/

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < sleep_time)
		usleep(500);
}
