/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/18 20:12:23 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	select_msg(t_philo *philosopher, t_status state)
{
	if (state == DEAD)
		printf("%s %ld %d  died ☠️ %s\n", RED, get_time_in_ms()
			-philosopher->app->start_time, philosopher->id, NC);
	if (state == THINKING)
		printf("%s %ld %d  is thinking 💬 %s\n", CYAN, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id, NC);
	if (state == EATING)
		printf("%s %ld %d  is eating 🍝 %s\n", GREEN, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id, NC);
	if (state == SLEEPING)
		printf("%s %ld %d  is sleeping 🛌 %s\n", MAGENTA, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id, NC);
	if (state == FORK)
		printf("%s %ld %d  has taken a fork 🍴 %s\n", YELLOW, get_time_in_ms()
			- philosopher->app->start_time, philosopher->id, NC);
}

void	print_status(t_philo *philosopher, t_status state)
{
	pthread_mutex_lock(&philosopher->app->write_lock);
	if (check_simulation_stopped(philosopher->app) == 1)
	{
		if (state == DEAD)
		{
			select_msg(philosopher, DEAD);
			pthread_mutex_unlock(&philosopher->app->write_lock);
			return ;
		}
		pthread_mutex_unlock(&philosopher->app->write_lock);
		return ;
	}
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
	pthread_mutex_unlock(&philosopher->app->write_lock);
}
