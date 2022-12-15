/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:11 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/15 20:26:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

 t_philo	*create_philosopher(t_app *app, int id)
{
	t_philo	*philosopher;

	philosopher = malloc(sizeof(t_philo));
	if(!philosopher)
		return (NULL);
	philosopher->id = id;
	philosopher->settings = app->settings;
	return (philosopher);
}

 void	init_mutex(t_app *app)
{
	size_t i;

	i = 0;
	app->fork = malloc(sizeof(pthread_mutex_t) * app->settings.num_philosophers + 1);
	if(!app->fork)
		return ;
	while(i < app->settings.num_philosophers)
	{
		pthread_mutex_init(&app->fork[i], NULL);
		i++;
	}
}

void	init_philosophers(t_app *app)
{
	size_t i;

	i = 0;
	init_mutex(app);
	app->philo = malloc(sizeof(t_philo) * app->settings.num_philosophers + 1);
	if(!app->philo)
	{
		app->philo = NULL;
		return ;
	}
	while(i < app->settings.num_philosophers)
	{
		app->philo[i] = create_philosopher(app, i);
		if(!app->philo[i])
			return ;
		i++;
	}
}