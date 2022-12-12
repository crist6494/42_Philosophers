/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:26:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/12 16:53:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	validate_parsing(t_parser parser)
{
	if(parser.return_value == 1)
		return(1);
	else if (parser.return_value == 2)
		printf("%s  %s\n", MSG_TOO_MANY_ARGUMENTS, MSG_USAGE);
	else if (parser.return_value == 3)
		printf("%s  %s\n", MSG_MISSING_ARGUMENTS, MSG_USAGE);
	else if (parser.return_value == 4)
		printf("%s  %s\n", MSG_WRONG_ARGUMENT_TYPE, MSG_USAGE);
	return (0);
}

void	give_values(t_parser *parser, int key, int value)
{
	if(key == 1)
		parser->num_philosophers = value;
	else if (key == 2)
		parser->time_to_die = value;
	else if (key == 3)
		parser->time_to_eat = value;
	else if (key == 4)
		parser->time_to_sleep = value;
	else if (key == 5)
		parser->num_times_must_eat = value;
}

 void	parsing(t_parser *parser, int argc, char **argv)
{
	int i;

	if(argc > 6)
		parser->return_value = 2;
	else if(argc < 5)
		parser->return_value = 3;
	else
	{
		i = 1;
		while (argv[i])
		{
			if(!is_number(argv[i])) //Preguntar alguien pq es en este orden y no en otro
			{
				parser->return_value = 4;
				return ;
			}
			give_values(parser, i, ft_atoi(argv[i]));
			i++;
		}
		parser->return_value = 1;		
	}
} 