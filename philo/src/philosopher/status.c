/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/17 20:43:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	select_msg(t_philo *philosopher, t_status state)
{
	if (state == DEAD)
		printf("%s %ld %d  died ☠️\n", RED, get_time_in_ms()
			-philosopher->app->start_time, philosopher->id);
	if (state == THINKING)
		printf("%s %ld %d  is thinking 💬\n", CYAN, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id);
	if (state == EATING)
		printf("%s %ld %d  is eating 🍝\n", GREEN, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id);
	if (state == SLEEPING)
		printf("%s %ld %d  is sleeping 🛌\n", MAGENTA, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id);
	if (state == FORK)
		printf("%s %ld %d  has taken a fork 🍴\n", YELLOW, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id);
}

void	print_status(t_philo *philosopher, t_status state)
{
	if (check_simulation_stopped(philosopher->app) == 1)
	{
		if (state == DEAD)
		{
			select_msg(philosopher, DEAD);
			return ;
		}
		return ;
	}
	else
	{
		if (state == THINKING)
			select_msg(philosopher, THINKING);
		else if (state == EATING)
			select_msg(philosopher, EATING);
		else if (state == SLEEPING)
			select_msg(philosopher, SLEEPING);
		else if (state == FORK)
			select_msg(philosopher, FORK);
		else if (state == DEAD)
			select_msg(philosopher, DEAD);
	}
}
