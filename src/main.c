/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/13 00:43:29 by cmorales         ###   ########.fr       */
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

void	start(t_app *app)
{
	size_t	i;
	
	i = 0;
	app->forks = create_mutex(app);
	app->philos = create_philosopher(app, app->settings.num_philosophers);
	//if(pthread_create(&app->philos[i].thread, NULL, &supervisor_routine, &app->philos[i]) != 0)
	//	return ;
	//printf("%zu\n", app->philos->last_meal);
	while(i < app->settings.num_philosophers)
	{
		
		if(pthread_create(&app->philos[i].thread, NULL, &philo_routine, &app->philos[i]) != 0)
			return ;
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
	//printf("%zu\n", app.settings.time_to_die);
	//printf("%zu\n", app.settings.time_to_eat);
	//printf("%zu\n", app.settings.time_to_sleep);
	//write(1, "hola\n", 4);
	start(&app);
	join_threads(&app);
	clear_philosophers(&app);
} 