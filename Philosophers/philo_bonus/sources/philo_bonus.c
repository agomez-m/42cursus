/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:55:47 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 18:28:56 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

t_data	*ft_get_data(char **argv)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
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

int	ft_waiter(t_philo *p)
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

/*
	puntero temporal tmp para iterar sobre los filósofos
	philo_waiter espera a que todos los filósofos terminen sus cenas 
	y luego finaliza todos los procesos asociados a los filósofos
	se encarga de esperar a que todos los semáforos sem_end estén en 1, 
	lo que indica que todos los filósofos han terminado sus cenas
*/

int	main(int argc, char **argv)
{
	t_data	*d;
	t_philo	*p;

	if (ft_check_args(argc, argv) == 1)
		return (1);
	d = ft_get_data(argv);
	if (!d)
		return (1);
	p = ft_philo_init(d);
	if (!p)
		return (1);
	if (ft_sem_init(d) == 1 || ft_run(p) == 1)
	{
		ft_philofree(p);
		return (1);
	}
	ft_waiter(p);
	ft_destroyer(d);
	ft_philofree(p);
	return (0);
}
