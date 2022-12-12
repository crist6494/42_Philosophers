/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/12 16:54:40 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_void(void)
{
	system("leaks -q philo");
}

int main (int argc, char **argv)
{
	t_parser parser;
	
	//atexit(ft_void);
	parsing(&parser, argc, argv);
	validate_parsing(parser);
	printf("Num of philos is %d\n", parser.num_philosophers);
	printf("Time to die is %d\n", parser.time_to_die);
	printf("Time to eat  is %d\n", parser.time_to_eat);
	printf("Time to sleep is %d\n", parser.time_to_sleep);
	printf("Num of time must eat is %d\n", parser.num_times_must_eat);  
} 