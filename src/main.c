/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/02 18:19:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int main (int argc, char **argv)
{
	t_parser parsing;
	
	parser(&parsing, argc, argv);
	validate_parsing(parsing);
}