/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:11 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/19 20:45:43 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_philo	*create_philosopher(t_app *app,int n_philos)
{
	t_philo	*philosopher;
	size_t i;
	
	i = 0;
	philosopher = (t_philo *)malloc(sizeof(t_philo) * n_philos);
	if(!philosopher)
		return (NULL);
	while(i < (size_t)n_philos)
	{
		philosopher[i].id = i;
		philosopher[i].settings = app->settings;
		philosopher[i].state = THINKING;
		i++;
	}
	return (philosopher);
}

pthread_mutex_t	*create_mutex(t_app *app)
{
	size_t i;
	pthread_mutex_t	*fork;
	
	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * app->settings.num_philosophers);
	if(!fork)
		return (NULL);
	while(i < app->settings.num_philosophers)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
	return(fork);
}

void	init_philosophers(t_app *app)
{
	size_t i;

	i = 0;
	app->fork = create_mutex(app);
	app->philos = create_philosopher(app, app->settings.num_philosophers);
	/* while ((i < app->settings.num_philosophers))
	{
		give_status(&app->philos[i], EATING);
		i++;
	} */
	
}
void	*philo_routine(void *data)
{
	t_philo	*philosopher;
	
	philosopher = ((t_philo *)data);
	printf("Id del philo %d\n", philosopher->id);
	printf("Estado del filosofo %d\n", philosopher->state);
	return((void *)0);
}

void	start(t_app *app)
{
	size_t	i;

	i = 0;
	while(i < app->settings.num_philosophers)
	{
		if(pthread_create(&app->philos[i].thread, NULL, &philo_routine, &app->philos[i]) != 0)
			return ;
		i++;
	}
} 


