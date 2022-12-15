/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:34 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/15 20:33:22 by cmorales         ###   ########.fr       */
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

# include "./error_msg.h"

#define YELLOW	"\e[33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

/******************************************************************************
*                                 Structures                                  *
******************************************************************************/

typedef struct	s_settings
{
	int 	return_value;
	size_t	num_philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int 	num_times_must_eat;
}t_settings;


typedef struct s_philo
{
	t_settings	settings;
	int			id;	
}t_philo;

typedef struct s_app
{
	t_philo		**philo;
	t_settings	settings;
	pthread_mutex_t	*fork;
	
}t_app;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/


/*----------Parser----------*/
int		validate_parsing(t_settings settings);
void	parsing(t_settings *settings, int argc, char **argv);


/*----------Parser_utils----------*/
int		is_number(char *str);
int		ft_atoi(char *str);
void	ft_void(void);

/*----------Init----------*/
t_philo		*create_philosopher(t_app *app, int id);
void		init_mutex(t_app *app);
void		init_philosophers(t_app *app);

/*----------Clear----------*/
void	clear_philosophers(t_app *app);

#endif