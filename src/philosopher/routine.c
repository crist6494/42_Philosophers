/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:30:35 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/12 20:30:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

 static void	eat_sleep_routine(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher,FORK);
	printf("%s El philo %d cogio el tenedor %d de su derecha\n",CYAN,philosopher->id,philosopher->right_fork);
	pthread_mutex_lock(&philosopher->app->forks[philosopher->left_fork]);
	print_status(philosopher,FORK);
	printf("%s El philo %d cogio el tenedor %d de su izquierda\n",CYAN,philosopher->id,philosopher->left_fork);
	print_status(philosopher,EATING);
	philosopher->last_meal = get_time_in_ms();
	philo_sleep(philosopher->app, philosopher->settings.time_to_eat);
	philosopher->meals++;
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher,SLEEPING);
	philo_sleep(philosopher->app, philosopher->settings.time_to_sleep);
} 

static void	*philo_alone(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->left_fork]);
	print_status(philosopher,FORK);
	philo_sleep(philosopher->app, philosopher->settings.time_to_die);
	print_status(philosopher,DEAD);
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philosopher;
	
	philosopher = ((t_philo *)data);
	if(philosopher->settings.time_to_die == 0)
		return(0);
	if(philosopher->app->settings.num_philosophers == 1)
		return (philo_alone(philosopher));
	while(1)
	{
		eat_sleep_routine(philosopher);
		sleep(235);
	}
	return((void *)0);
}
