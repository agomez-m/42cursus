/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:56:48 by agomez-m          #+#    #+#             */
/*   Updated: 2024/02/01 16:41:37 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> // usleep()
# include <stdio.h> // printf()
# include <stdlib.h> // malloc() free() exit() 
# include <sys/time.h> // gettimeofday() 
# include <stdint.h> // uint64_t 
# include <stdbool.h> // bool
# include <pthread.h> // pthread_create() pthread_join()

# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}			t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}				t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		die_time;
	u_int64_t		start_time;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;

// eat
int			ft_take_left_fork(t_philo *philo);
int			ft_take_right_fork(t_philo *philo);
int			ft_take_forks(t_philo *philo);
void		ft_drop_forks(t_philo *philo);
int			ft_eat(t_philo *philo);
// init
int			malloc_philsforksths(t_data *data);
int			init_data(t_data *data, int argc, char **argv);
int			init_philos(t_data *data);
int			init_forks(t_data *data);
// input
int			check_input_digits(int argc, char **argv);
int			wrong_input_check(int argc, char **argv);
int			ft_check_args(int argc, char **argv);
// mutextime
uint64_t	get_mutex_die_time(t_data *data);
uint64_t	get_mutex_eat_time(t_data *data);
uint64_t	get_mutex_sleep_time(t_data *data);
uint64_t	get_mutex_start_time(t_data *data);
uint64_t	get_mutex_last_eat_time(t_philo *philo);
//mutexget
int			get_mutex_nb_philos(t_data *data);
int			get_mutex_nb_meals_philo_had(t_philo *philo);
bool		get_mutex_keep_iter(t_data *data);
t_state		get_mutex_philo_state(t_philo *philo);
// mutexset
void		set_mutex_keep_iterating(t_data *data, bool set_to);
void		set_mutex_philo_state(t_philo *philo, t_state state);
void		update_mutex_nb_meals_had(t_philo *philo);
void		update_mutex_last_meal_time(t_philo *philo);
// philo
int			ft_init_program(int argc, char **argv);
int			main(int argc, char **argv);
// routine
void		*ft_routine(void *philo_p);
void		*ft_all_alive_routine(void *data_p);
void		*ft_all_full_routine(void *data_p);
// sleepthink
int			ft_sleep(t_philo *philo);
int			ft_think(t_philo *philo);
// state
bool		ft_philo_died(t_philo *philo);
bool		ft_is_philo_full(t_data *data, t_philo *philo);
void		ft_dead_all_philos(t_data *data);
// threads
int			init_threads(t_data *data);
int			join_threads(t_data *data);
void		ft_free_data(t_data *data);
// time
uint64_t	ft_get_time(void);
void		ft_usleep(uint64_t sleep_time);
// utils
int			ft_atoi(char *str);
int			handle_1_philo(t_philo *philo);
bool		nb_meals_optional(t_data *data);
void		ft_print_msg(t_data *data, int id, char *msg);


#endif