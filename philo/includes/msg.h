/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:27:29 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/18 20:44:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include "./philo.h"

/*------ERROR_MSG----------*/

# define MSG_USAGE "Usage: <number_of_philosophers> <time_to_die>\
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"
# define MSG_MISSING_ARGUMENTS "Error: Missing arguments!"
# define MSG_TOO_MANY_ARGUMENTS "Error: Too many arguments!"
# define MSG_WRONG_ARGUMENT_TYPE "Error: Wrong argument type!"
# define MSG_OVERFLOW_PHILOS "Error: invalid input!\
(there must be between 1 and 250 philosophers)."
# define MSG_OVERFLOW_INT "Error: is not a valid unsigned integer(there must to be \
between 0 and 2147483647)"

typedef enum e_error
{
	TOO_MANY_ARGUMENTS = 2,
	MISSING_ARGUMENTS = 3,
	WRONG_ARGUMENT_TYPE = 4,
	OVERFLOW_NUM_PHILOS = 5,
	OVERFLOW_NUM_INT = 6,
}t_error;

#endif
