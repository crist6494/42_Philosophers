/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:34 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/19 00:03:39 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# include "./msg.h"

# define YELLOW	"\e[33m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define NC	"\e[0m"
# define MAGENTA	"\x1B[35m"
# define CYAN	"\x1B[36m"

/******************************************************************************
*                                 Structures                                  *
******************************************************************************/

typedef enum e_status
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
	DEAD = 3,
	FORK = 4,
}t_status;

typedef struct s_app	t_app;

typedef struct s_settings
{
	int		return_value;
	size_t	num_philosophers;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		num_times_must_eat;
}t_settings;

typedef struct s_philo
{
	t_app		*app;
	t_settings	settings;
	int			id;	
	int			left_fork;
	int			right_fork;
	int			meals;
	time_t		last_meal;
	pthread_t	thread;
}t_philo;

typedef struct s_app
{
	time_t			start_time;
	int				stop_signal;
	pthread_t		supervisor;
	t_settings		settings;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	signal_lock;
}t_app;

/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/

/*----------Parser----------*/
int				is_number(char *str);
int				ft_atoi(char *str);
int				validate_parsing(t_settings settings);
void			parsing(t_settings *settings, int argc, char **argv);

/*----------Init----------*/
t_philo			*create_philosopher(t_app *app, int n_philos);
pthread_mutex_t	*create_mutex(t_app *app);
int				init_mutex(t_app *app);

/*----------Routine----------*/
void			*philo_routine(void *data);

/*------Supervisor_routine----------*/
void			*supervisor_routine(void *data);
int				check_simulation_stopped(t_app *app);
int				someone_dead(t_philo *philosopher);
int				check_dead_and_full_meals(t_app *app);

/*----------Status----------*/
void			print_status(t_philo *philospher, t_status state);

/*----------Clear----------*/
void			clear_philosophers(t_app *app);
void			clear_mutex(t_app *app);

/*----------Utils----------*/
void			ft_void(void);
time_t			get_time_in_ms(void);
void			philo_sleep(t_app *app, time_t time_sleeping);
void			init_parameter(t_settings *settings);
void			start_delay(time_t start_time);

#endif