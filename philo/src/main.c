/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/19 18:22:26 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	start(t_app *app)
{
	unsigned int	i;

	i = 0;
	app->philos = create_philosopher(app, app->settings.num_philosophers);
	if (!init_mutex(app))
		return (0);
	app->start_time = get_time_in_ms() + 50;
	while (i < app->settings.num_philosophers)
	{
		if (pthread_create(&app->philos[i].thread, NULL, &philo_routine,
				&app->philos[i]) != 0)
			return (0);
		i++;
	}
	if (app->settings.num_philosophers > 1)
	{
		if (pthread_create(&app->supervisor, NULL, &supervisor_routine,
				app) != 0)
			return (0);
	}
	return (1);
}

static void	stop(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->settings.num_philosophers)
	{
		pthread_join(app->philos[i].thread, NULL);
		i++;
	}
	if (app->settings.num_philosophers > 1)
		pthread_join(app->supervisor, NULL);
	clear_mutex(app);
	clear_philosophers(app);
}

int	main(int argc, char **argv)
{
	t_app	app;

	init_parameter(&app.settings);
	parsing(&app.settings, argc, argv);
	if (!validate_parsing(app.settings))
		return (EXIT_FAILURE);
	if (!start(&app))
		return (EXIT_FAILURE);
	stop(&app);
	return (EXIT_SUCCESS);
}
	//atexit(ft_void);
