/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/16 17:03:28 by cmorales         ###   ########.fr       */
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

int main (int argc, char **argv)
{
	t_app app;
	
	//atexit(ft_void);
	init_parameter(&app.settin§gs);
	parsing(&app.settings, argc, argv);
	validate_parsing(app.settings);
	//printf("Num of philos is %zu\n", app.settings.num_philosophers);
	//printf("Time to die is %zu\n", app.settings.time_to_die);
	//printf("Time to eat  is %zu\n", app.settings.time_to_eat);
	//printf("Time to sleep is %zu\n", app.settings.time_to_sleep);
	//printf("Num of time must eat is %d\n", app.settings.num_times_must_eat);  
	init_philosophers(&app);
	clear_philosophers(&app);
} 