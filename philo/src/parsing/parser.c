/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:26:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/17 19:46:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	validate_parsing(t_settings settings)
{
	if (settings.return_value == 1)
		return (1);
	else if (settings.return_value == TOO_MANY_ARGUMENTS)
		printf("%s  %s\n", MSG_TOO_MANY_ARGUMENTS, MSG_USAGE);
	else if (settings.return_value == MISSING_ARGUMENTS)
		printf("%s  %s\n", MSG_MISSING_ARGUMENTS, MSG_USAGE);
	else if (settings.return_value == WRONG_ARGUMENT_TYPE)
		printf("%s  %s\n", MSG_WRONG_ARGUMENT_TYPE, MSG_USAGE);
	return (0);
}

void	give_values(t_settings *settings, int key, int value)
{
	if (key == 1)
		settings->num_philosophers = value;
	else if (key == 2)
		settings->time_to_die = value;
	else if (key == 3)
		settings->time_to_eat = value;
	else if (key == 4)
		settings->time_to_sleep = value;
	else if (key == 5)
		settings->num_times_must_eat = value;
}

void	parsing(t_settings *settings, int argc, char **argv)
{
	int	i;

	if (argc > 6)
		settings->return_value = TOO_MANY_ARGUMENTS;
	else if (argc < 5)
		settings->return_value = MISSING_ARGUMENTS;
	else
	{
		i = 1;
		while (argv[i])
		{
			if (!is_number(argv[i]))
			{
				settings->return_value = WRONG_ARGUMENT_TYPE;
				return ;
			}
			give_values(settings, i, ft_atoi(argv[i]));
			i++;
		}
		settings->return_value = 1;
	}
}
