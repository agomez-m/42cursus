/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:47:37 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/22 11:43:00 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	if (!(str[count] >= '0' && str[count] <= '9'))
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * sign);
}

int	handle_1_philo(t_philo *philo)
{
	ft_take_left_fork(philo);
	ft_usleep(get_mutex_die_time(philo->data));
	set_mutex_philo_state(philo, DEAD);
	return (1);
}

bool	nb_meals_optional(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

void	ft_print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = ft_get_time() - get_mutex_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_mutex_keep_iter(data))
		printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}
