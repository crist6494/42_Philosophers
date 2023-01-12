/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:50:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/12 20:09:47 by cmorales         ###   ########.fr       */
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
	while(get_time_in_ms() < wake_up)
	{
		if(check_simulation_stopped(app) == 1)
			break;
		usleep(235);
	}
}