/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/16 20:10:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

pthread_mutex_t	*create_mutex(t_app *app)
{
	size_t i;
	pthread_mutex_t	*forks;
	
	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * app->settings.num_philosophers);
	if(!forks)
		return (NULL);
	while(i < app->settings.num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return(forks);
}

void	assing_forks(t_philo *philosopher)
{
	int id;
	int	n_philos;

	
	id = philosopher->id;
	n_philos = philosopher->settings.num_philosophers;	
	philosopher->left_fork = id;
	philosopher->right_fork = (id + 1) % n_philos; 
	if(philosopher->id % 2 == 0)
	{
		philosopher->left_fork = (id + 1) % n_philos;
		philosopher->right_fork = id;
	}
	//printf("%s%d   %d%s\n", YELLOW,philosopher->left_fork,philosopher->right_fork,NC); 
}

t_philo	*create_philosopher(t_app *app, int n_philos)
{
	t_philo	*philosopher;
	size_t i;
	
	i = 0;
	philosopher = (t_philo *)malloc(sizeof(t_philo) * n_philos);
	if(!philosopher)
		return (NULL);
	while(i < (size_t)n_philos)
	{ 
		if(pthread_mutex_init(&philosopher[i].meals_lock, NULL) != 0)
			return (NULL);
		philosopher[i].id = i;
		philosopher[i].settings = app->settings;
		philosopher[i].app = app;
		philosopher[i].state = THINKING;
		philosopher[i].meals = 0;
		assing_forks(&philosopher[i]);
		i++;
	}
	return (philosopher);
}
