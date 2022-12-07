/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:26:27 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/05 17:48:09 by cmorales         ###   ########.fr       */
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
			if(!is_number(argv[i]))
			{
				parser->return_value = 4;
				return ;
			}
			i++;
		}
		parser->return_value = 1;		
	}
} 