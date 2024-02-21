/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:55:47 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 16:47:16 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_data	*get_data(char **argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	ft_bzero(d, sizeof(t_data));
	d->n_philo = ft_long_atoi(argv[1]);
	d->t_die = ft_long_atoi(argv[2]);
	d->t_eat = ft_long_atoi(argv[3]);
	d->t_sleep = ft_long_atoi(argv[4]);
	if (argv[5] != NULL)
	{
		d->cap = malloc(sizeof(long long));
		*d->cap = ft_long_atoi(argv[5]);
	}
	d->t_die = d->t_die * 1000;
	d->t_eat = d->t_eat * 1000;
	d->t_sleep = d->t_sleep * 1000;
	if (d->n_philo % 2 && (d->t_die - d->t_eat - d->t_sleep) / 2 > 0)
		d->t_think = (d->t_die - d->t_eat - d->t_sleep) / 2;
	return (d);
}

int	philo_waiter(t_philo *p)
{
	int		i;
	t_philo	*tmp;

	tmp = p;
	i = p->d->n_philo;
	while (i--)
		sem_wait(p->d->sem_end);
	while (tmp->next != NULL && tmp->next != p)
	{
		kill(tmp->pid, SIGKILL);
		tmp = tmp->next;
	}
	kill(tmp->pid, SIGKILL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*d;
	t_philo	*p;

	if (ft_check_args(argc, argv) == 1)
		return (1);
	d = get_data(argv);
	if (!d)
		return (1);
	p = philo_init(d);
	if (!p)
		return (1);
	if (seminit(d) == 1 || set_processes(p) == 1)
	{
		philofree(p);
		return (1);
	}
	philo_waiter(p);
	semdestroyer(d);
	philofree(p);
	return (0);
}
