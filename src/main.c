/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/20 20:27:49 by cmorales         ###   ########.fr       */
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
	//printf("Num of philos is %zu\n", app.settings.num_philosophers);
	//printf("Time to die is %zu\n", app.settings.time_to_die);
	//printf("Time to eat  is %zu\n", app.settings.time_to_eat);
	//printf("Time to sleep is %zu\n", app.settings.time_to_sleep);
	//printf("Num of time must eat is %d\n", app.settings.num_times_must_eat);  
	init_philosophers(&app);
	//start(&app);
	join_threads(&app);
	clear_philosophers(&app);
} 