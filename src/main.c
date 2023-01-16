/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/17 00:18:34 by cmorales         ###   ########.fr       */
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


void	start(t_app *app)
{
	unsigned int	i;
	
	i = 0;
	app->forks = create_mutex(app);
	app->philos = create_philosopher(app, app->settings.num_philosophers);
	//printf("app %d\n", app->settings.num_times_must_eat);
	//printf("philo main %d\n", app->philos[1].id);
	//app->start_time = get_time_in_ms() + (app->settings.num_philosophers * 2 * 10);
	while(i < app->settings.num_philosophers)
	{
		if(pthread_create(&app->philos[i].thread, NULL, &philo_routine, &app->philos[i]) != 0)
			return ;
		i++;
	}
	if(app->settings.num_philosophers > 1)
	{
		if(pthread_create(&app->supervisor, NULL, &supervisor_routine, app) != 0)
			return ;  
	}
} 

void	stop(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->settings.num_philosophers)
	{
		pthread_join(app->philos[i].thread, NULL);
		i++;
	}
	if(app->settings.num_philosophers > 1)
		pthread_join(app->supervisor, NULL);
	clear_mutex(app); 
	clear_philosophers(app);
}

int main (int argc, char **argv)
{
	t_app app;
	
	//atexit(ft_void);
	app.start_time = get_time_in_ms();
	init_parameter(&app.settings);
	parsing(&app.settings, argc, argv);
	validate_parsing(app.settings);
	start(&app);
	stop(&app);
	return (EXIT_SUCCESS);
} 