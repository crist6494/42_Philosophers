/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:26:17 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/11 23:38:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	set_stop_signal(t_app *app, bool state)
{
	app->stop_signal = state;
}

bool	check_simulation_is_stopped(t_app app)
{
	if(app.stop_signal == true)
		return (true);
	return(false);
}

bool	should_be_dead(t_philo *philosopher)
{
	time_t	time;

	time = get_time_in_ms();
	if((time - philosopher->last_meal) >= philosopher->settings.time_to_die)
	{
		set_stop_signal(philosopher->app, true);
		print_status(philosopher, DEAD);
		return(true);
	}
	return(false);	
}

bool	everyone_is_full_or_someone_dead(t_app *app)
{
	size_t	i;
	bool	is_full;

	i = 0;
	is_full = true;
	while(i < app->settings.num_philosophers)
	{
		if(should_be_dead(&app->philos[i]) == true)
			return(true);
		if(app->settings.num_times_must_eat > 0)
		{
			if(app->philos[i].meals >= app->settings.num_times_must_eat)
				is_full = true;
		}
		i++;
	}
	if(app->settings.num_times_must_eat > 0 && is_full == true)
	{
		set_stop_signal(app, true);
		return(true);
	}
	return (false);
}