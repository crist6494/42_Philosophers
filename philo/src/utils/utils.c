/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:50:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/18 19:39:59 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

time_t	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	philo_sleep(t_app *app, time_t time_sleeping)
{
	time_t	wake_up;

	wake_up = get_time_in_ms() + time_sleeping;
	while (get_time_in_ms() < wake_up)
	{
		if (check_simulation_stopped(app) == 1)
			return ;
		usleep(235);
	}
}

void	start_delay(time_t start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}

void	init_parameter(t_settings *settings)
{
	settings->num_philosophers = 0;
	settings->time_to_die = 0;
	settings->time_to_eat = 0;
	settings->time_to_sleep = 0;
	settings->num_times_must_eat = 0;
}
