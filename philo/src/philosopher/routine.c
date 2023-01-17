/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:30:35 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/17 19:57:02 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	eat_sleep_routine(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher, FORK);
	pthread_mutex_lock(&philosopher->app->forks[philosopher->left_fork]);
	print_status (philosopher, FORK);
	print_status (philosopher, EATING);
	philosopher->last_meal = get_time_in_ms();
	if (check_simulation_stopped(philosopher->app) == 0)
		philosopher->meals++;
	philo_sleep(philosopher->app, philosopher->settings.time_to_eat);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher, SLEEPING);
	philo_sleep(philosopher->app, philosopher->settings.time_to_sleep);
}

static void	think_routine(t_philo *philosopher, int delay)
{
	time_t	think_time;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	last_meal;

	time_to_die = philosopher->settings.time_to_die;
	time_to_eat = philosopher->settings.time_to_eat;
	last_meal = philosopher->last_meal;
	think_time = (time_to_die - (get_time_in_ms() - last_meal) - time_to_eat) / 2;
	if (think_time < 0)
		think_time = 0;
	if (think_time == 0 && delay == 1)
		think_time = 1;
	if (think_time > 600)
		think_time = 200;
	print_status(philosopher, THINKING);
	philo_sleep(philosopher->app, think_time);
}

static void	*philo_alone(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->app->forks[philosopher->right_fork]);
	print_status(philosopher, FORK);
	philo_sleep(philosopher->app, philosopher->settings.time_to_die);
	print_status(philosopher, DEAD);
	pthread_mutex_unlock(&philosopher->app->forks[philosopher->right_fork]);
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philosopher;

	philosopher = ((t_philo *)data);
	philosopher->last_meal = philosopher->app->start_time;
	//sim_start_delay(philosopher->app->start_time);
	if (philosopher->settings.time_to_die == 0)
		return (NULL);
	if (philosopher->app->settings.num_philosophers == 1)
		return (philo_alone(philosopher));
	else if (philosopher->id % 2)
		think_routine(philosopher, 1);
	while (check_simulation_stopped(philosopher->app) == 0)
	{
		eat_sleep_routine(philosopher);
		think_routine(philosopher, 0);
	}
	return ((void *)0);
}
