/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:26:17 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/19 17:19:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	set_stop_signal(t_app *app, int state)
{
	pthread_mutex_lock(&app->signal_lock);
	app->stop_signal = state;
	pthread_mutex_unlock(&app->signal_lock);
}

int	check_simulation_stopped(t_app *app)
{
	int	s;

	s = 0;
	pthread_mutex_lock(&app->signal_lock);
	if (app->stop_signal == 1)
		s = 1;
	pthread_mutex_unlock(&app->signal_lock);
	return (s);
}

int	someone_dead(t_philo *philosopher)
{
	time_t	time;

	time = get_time_in_ms();
	if ((time - philosopher->last_meal) > philosopher->settings.time_to_die)
	{
		set_stop_signal(philosopher->app, 1);
		print_status(philosopher, DEAD);
		return (1);
	}
	return (0);
}

int	check_dead_and_full_meals(t_app *app)
{
	unsigned int	i;
	unsigned int	full;

	i = 0;
	full = 0;
	while (i < app->settings.num_philosophers)
	{
		if (someone_dead(&app->philos[i]) == 1)
			return (1);
		if (app->settings.num_times_must_eat == 0)
			return (1);
		if (app->settings.num_times_must_eat > 0)
		{
			if (app->philos[i].meals >= app->settings.num_times_must_eat)
				full++;
		}
		i++;
	}
	if (app->settings.num_times_must_eat > 0
		&& full == app->settings.num_philosophers)
	{
		set_stop_signal(app, 1);
		return (1);
	}
	return (0);
}

void	*supervisor_routine(void *data)
{
	t_app	*app;

	app = ((t_app *) data);
	set_stop_signal(app, 0);
	start_delay(app->start_time);
	while (1)
	{
		if (check_dead_and_full_meals(app) == 1)
			return (NULL);
		usleep(235);
	}
	return (NULL);
}
