/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:56:48 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/21 16:43:27 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define INTMAX	2147483647
# define INTMIN	-2147483648

typedef struct s_data
{
	int				n_philo;
	long long		t_die;
	long long		t_eat;
	long long		t_sleep;
	long long		t_think;
	long long		*cap;
	struct timeval	offset;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	sem_t			*sem_death;
	sem_t			*sem_go;
	sem_t			*sem_end;
	sem_t			*sem_time;
}	t_data;

typedef struct s_philo
{
	int					id;
	pid_t				pid;
	t_data				*d;
	struct timeval		t0;
	struct timeval		t;
	int					meals;
	struct s_philo		*prev;
	struct s_philo		*next;
}	t_philo;

int				ft_check_args(int argc, char **argv);
int				datacheck(t_data *d);
t_data			*get_data(char **argv);

int				set_time(t_philo *p);
struct timeval	now(t_philo *p);
long long		utime(struct timeval t);
long long		deltatime(struct timeval t0, struct timeval t1);

t_philo			*philo_new(int id, t_data *data);
void			philo_add(t_philo **p, t_philo *new);
t_philo			*philo_init(t_data *data);
int				set_processes(t_philo *p);
int				seminit(t_data *data);

int				grab_fork(t_philo *p);
int				eat(t_philo *p);
int				nap(t_philo *p);
int				think(t_philo *p);
int				philo_routine(t_philo *p);

int				set_offset(t_philo *p);
int				deathcheck(t_philo *p);
int				printstate(t_philo *p, int state, struct timeval t);
void			*bigbrother(void *philo);

int				drop_fork(t_philo *p);
void			endr(t_philo *p);
int				philo_waiter(t_philo *p);

int				semunlinker(void);
int				semdestroyer(t_data *d);
int				datafree(t_data *d);
void			philofree(t_philo *p);

size_t			ft_strlen(const char *s);
long long		ft_long_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
long long		ft_min(long long a, long long b);

#endif