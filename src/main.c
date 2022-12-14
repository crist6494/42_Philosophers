/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/09 20:38:14 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_void(void)
{
	system("leaks -q philo");
}

void	init_parameter(t_settings *settings)
{
	settings->num_philosophers = 0;
	settings->time_to_die = 0;
	settings->time_to_eat = 0;
	settings->time_to_sleep = 0;
	settings->num_times_must_eat = 0;
}

void	join_threads(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->settings.num_philosophers)
	{
		pthread_join(app->philos[i].thread, NULL);
		i++;
	}
}

int main (int argc, char **argv)
{
	t_app app;
	
	//atexit(ft_void);
	init_parameter(&app.settings);
	parsing(&app.settings, argc, argv);
	validate_parsing(app.settings);
	//write(1, "hola\n", 4);
	start(&app);
	join_threads(&app);
	clear_philosophers(&app);
} 