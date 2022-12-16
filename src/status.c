/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:19 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/16 16:48:35 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

time_t	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	give_status(t_philo *philospher, t_status state)
{
	char	*msg;

	if (state == THINKING)
		msg = MSG_THINKING;
	else if (state == EATING)
		msg = MSG_EATING;
	else if (state == SLEEPING)
		msg = MSG_SLEEPING;
	else if (state == DEAD)
		msg = MSG_DEAD;
	else if (state == FORK)
		msg = MSG_FORK;
	printf(msg, get_time_in_ms(), philospher->id);	
}
 