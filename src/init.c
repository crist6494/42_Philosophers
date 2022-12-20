/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:11:11 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/20 20:37:38 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

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
		philosopher[i].id = i;
		philosopher[i].settings = app->settings;
		philosopher[i].state = THINKING;
		philosopher[i].meals = 0;
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
	printf("%s%d   %d%s\n", YELLOW,philosopher->left_fork,philosopher->right_fork,NC); 
}

void	init_philosophers(t_app *app)
{
	size_t i;

	i = 0;
	app->fork = create_mutex(app);
	app->philos = create_philosopher(app, app->settings.num_philosophers);
	while ((i < app->settings.num_philosophers))
	{
		printf("Soy el filosofo %zu\n", i);
		assing_forks(&app->philos[i]);
		//give_status(&app->philos[i], SLEEPING);
		i++;
	} 
	
}



