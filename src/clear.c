/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:18:37 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/19 18:58:07 by cmorales         ###   ########.fr       */
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
	free(app->fork);
	free(app->philos);
}