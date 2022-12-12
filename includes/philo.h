/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:34 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/12 16:34:39 by cmorales         ###   ########.fr       */
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

typedef struct	s_parser
{
	int return_value;
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int num_times_must_eat;
}t_parser;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/


/*----------Parser----------*/
int		validate_parsing(t_parser parser);
void	parsing(t_parser *parser, int argc, char **argv);


/*----------Parser_utils----------*/
int		is_number(char *str);
int		ft_atoi(char *str);

void	ft_void(void);


#endif