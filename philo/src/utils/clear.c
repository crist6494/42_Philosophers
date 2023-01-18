/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:18:37 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/18 19:30:26 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	clear_mutex(t_app *app)
{
	size_t	i;

	i = 0;
	while (i < app->settings.num_philosophers)
	{
		pthread_mutex_destroy(&app->forks[i]);
		i++;
	}
}

void	clear_philosophers(t_app *app)
{
	free(app->forks);
	free(app->philos);
}

void	ft_void(void)
{
	system("leaks -q philo");
}
