/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:27:29 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/20 18:37:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H


/*------ERROR_MSG----------*/

# define MSG_USAGE "Usage: <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]"
# define MSG_MISSING_ARGUMENTS "Error: Missing arguments!"
# define MSG_TOO_MANY_ARGUMENTS "Error: Too many arguments!"
# define MSG_WRONG_ARGUMENT_TYPE "Error: Wrong argument type!"

typedef enum e_error
{
	TOO_MANY_ARGUMENTS = 2,
	MISSING_ARGUMENTS = 3,
	WRONG_ARGUMENT_TYPE = 4,
}t_error;


/*------STATUS_MSG----------*/
# define MSG_FORK "%lld %d has taken a fork 🍴\n" 
# define MSG_EATING "%lld %d is eating 🍝\n"
# define MSG_SLEEPING "%lld %d is sleeping 🛌\n"
# define MSG_THINKING "%lld %d is thinking 💬\n"
# define MSG_DEAD "%lld %d died ☠️\n"

#endif
