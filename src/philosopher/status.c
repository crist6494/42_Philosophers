/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/10 23:48:59 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	print_status(t_philo *philosopher, t_status state)
{
	char	*msg;

	if (state == THINKING)
	{
		msg = MSG_THINKING;
		printf(msg, CYAN, get_time_in_ms(), philosopher->id);		
	}
	else if (state == EATING)
	{
		msg = MSG_EATING;
		printf(msg, GREEN, get_time_in_ms(), philosopher->id);	
	}
	else if (state == SLEEPING)
	{
		msg = MSG_SLEEPING;
		printf(msg, MAGENTA, get_time_in_ms(), philosopher->id);		
	}
	else if (state == DEAD)
	{
		msg = MSG_DEAD;
		printf(msg, RED, get_time_in_ms(), philosopher->id);			
	}
	else if (state == FORK)
	{
		msg = MSG_FORK;
		printf(msg, YELLOW,get_time_in_ms(),philosopher->id);	
	}
}

useconds_t time_status(t_philo *philosopher, t_status state)
{
	useconds_t	time;

	if(state == EATING)
		time = philosopher->settings.time_to_eat;
	else if(state == SLEEPING)
		time = philosopher->settings.time_to_sleep;
	else if(state == DEAD)
		time = philosopher->settings.time_to_die;
	else
		time = 0;
	return (time * 1000);
}
