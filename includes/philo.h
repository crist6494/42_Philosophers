/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:34 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/02 18:15:05 by cmorales         ###   ########.fr       */
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

/******************************************************************************
*                                 Structures                                  *
******************************************************************************/

typedef struct	s_parser
{
	int return_value;
}t_parser;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/


/*----------Parser----------*/
int		validate_parsing(t_parser parsing);
void	parser(t_parser *parsing, int argc, char **argv);


/*----------Parser_utils----------*/
int is_number(char *str);
int	ft_atoi(char *str);


#endif