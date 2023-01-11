/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:30:35 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/11 23:05:17 by cmorales         ###   ########.fr       */
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
	usleep(time_status(philosopher, EATING));
	philosopher->meals++;
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher,SLEEPING);
	usleep(time_status(philosopher, SLEEPING));
} 

static void	*philo_alone(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->left_fork]);
	print_status(philosopher,FORK);
	usleep(time_status(philosopher, DEAD));
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