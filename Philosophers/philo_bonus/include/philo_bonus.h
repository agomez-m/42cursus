/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:56:48 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/04 18:06:58 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h> //fork() getpid() sleep() usleep() write() 
# include <stdio.h> //printf()
# include <stdlib.h> //malloc() free() exit()
# include <string.h> //memset() 
# include <sys/time.h> //gettimeofday() 
# include <stdint.h> //uint64_t 
# include <stdbool.h> //bool

# include <pthread.h> // pthread_create() pthread_detach() pthread_join()
# include <semaphore.h> // sem_open() sem_close() sem_post() sem_wait()
# include <sys/wait.h> // waitpid() 
# include <fcntl.h> // O_CREAT O_EXCL O_RDWR

# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING,
	SLEEPING,
	DEAD,
	FULL,
	IDLE,
	FINISH
}			t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	u_int64_t		last_eat_time;
	sem_t			*sem_philo;
}				t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		die_time;
	u_int64_t		start_time;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	pthread_t		monitor;
	t_philo			philo;
}				t_data;

// init.c
int			ft_init_data(t_data *data, int argc, char **argv);
// time.c
u_int64_t	ft_get_time(void);
void		ft_usleep(uint64_t sleep_time);
void		ft_usleep1(uint64_t sleep_time, uint64_t lastime);
// utils.c
int			ft_atoi(char *str);
char		*ft_itoa(int n);
char		*ft_strjoin(char *s1, char *s2);
// routine.c
int			set_philo(t_data *data, int id);
bool		stop_if(t_state state);
void		*ft_routine(t_data *data, int id);
// monitor.c
bool		someone_died(void);
bool		philo_died(t_data *data);
void		*monitor_death(void *data_p);
// eat.c
int			ft_eat(t_data *data);
bool		philo_is_full(t_data *data);
bool		nb_meals_option_given(t_data *data);
// semset.c
int			print_msg(t_data *data, char *msg);
void		print_sem(t_data *data, char *str);
// sleepthink.c
int			ft_sleep(t_data *data);
int			ft_think(t_data *data);
// input.c
int			ft_check_args(int argc, char **argv);

#endif