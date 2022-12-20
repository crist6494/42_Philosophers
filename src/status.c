/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:19 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/20 20:04:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	print_status(t_philo *philospher, t_status state)
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

useconds_t time_status(t_philo *philospher, t_status state)
{
	useconds_t	time;

	if(state == EATING)
		time = philospher->settings.time_to_eat;
	else if(state == SLEEPING)
		time = philospher->settings.time_to_sleep;
	else 
		time = 0;
	return (time * 1000);
}
