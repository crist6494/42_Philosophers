/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:11 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/16 17:03:55 by cmorales         ###   ########.fr       */
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
	/* printf("The id is %d\n", philosopher->id);
	printf("The settings is %zu\n", philosopher->settings.num_philosophers);
	printf("The settings is %d\n", philosopher->settings.num_times_must_eat);
	printf("The settings is %zu\n", philosopher->settings.time_to_eat);
	printf("The settings is %zu\n", philosopher->settings.time_to_sleep); */
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
	app->philos = malloc(sizeof(t_philo) * app->settings.num_philosophers + 1);
	if(!app->philos)
	{
		app->philos = NULL;
		return ;
	}
	while(i < app->settings.num_philosophers)
	{
		app->philos[i] = create_philosopher(app, i);
		if(!app->philos[i])
			return ;
		give_status(app->philos[i], EATING);
		i++;
	}
}
