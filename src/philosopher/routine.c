/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:30:35 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/09 20:38:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

 static void	eat_sleep_routine(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->left_fork]);
	print_status(philosopher,FORK);
	pthread_mutex_lock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher,FORK);
	print_status(philosopher,EATING);
	philosopher->limit = get_time_in_ms() + philosopher->settings.time_to_die;
	usleep(time_status(philosopher, EATING));
	philosopher->meals++;
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher,SLEEPING);
	usleep(time_status(philosopher, SLEEPING));
} 

void	*philo_routine(void *data)
{
	t_philo	*philosopher;
	
	philosopher = ((t_philo *)data);
	if(philosopher->settings.num_times_must_eat == 0)
		return(0);
	if(philosopher->settings.time_to_die == 0)
		return(0);
	while(1)
	{
		eat_sleep_routine(philosopher);
		break ;
	}
	return((void *)0);
}

void	start(t_app *app)
{
	app->forks = create_mutex(app);
	app->philos = create_philosopher(app, app->settings.num_philosophers);
	size_t	i;

	i = 0;
	while(i < app->settings.num_philosophers)
	{
		
		if(pthread_create(&app->philos[i].thread, NULL, &philo_routine, &app->philos[i]) != 0)
			return ;
		i++;
	}
} 