/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:18:37 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/16 11:01:48 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	clear_mutex(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->settings.num_philosophers)
	{
		pthread_mutex_destroy(&app->fork[i]);
		i++;
	}
	free(app->fork);
}


void	clear_philosophers(t_app *app)
{
	size_t	i;
	t_philo	*philosopher;

	i = 0;
	while (i < app->settings.num_philosophers)
	{
		philosopher = app->philos[i];
		free(philosopher);
		i++;
	}
	clear_mutex(app);
	free(app->philos);
}