/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:30:35 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/20 20:04:13 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*philo_routine(void *data)
{
	t_philo	*philosopher;
	
	philosopher = ((t_philo *)data);
	print_status(philosopher, THINKING);
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