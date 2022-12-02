/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:26:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/02 18:20:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	validate_parsing(t_parser parsing)
{
	if(parsing.return_value == 1)
		return(1);
	else if (parsing.return_value == 2)
		printf("%s %s\n", MSG_TOO_MANY_ARGUMENTS, MSG_USAGE);
	else if (parsing.return_value == 3)
		printf("%s %s\n", MSG_MISSING_ARGUMENTS, MSG_USAGE);
	else if (parsing.return_value == 4)
		printf("%s %s\n", MSG_WRONG_ARGUMENT_TYPE, MSG_USAGE);
	return (0);
}

 void	parser(t_parser *parsing, int argc, char **argv)
{
	int i;

	if(argc > 6)
		parsing->return_value = 2;
	else if(argc < 5)
		parsing->return_value = 3;
	else
	{
		i = 1;
		while (argv[i])
		{
			if(!is_number(argv[i]))
			{
				parsing->return_value = 4;
				return ;
			}
			i++;
		}
		parsing->return_value = 1;		
	}
} 