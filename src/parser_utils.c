/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:45 by cmorales          #+#    #+#             */
/*   Updated: 2022/12/02 18:11:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int is_number(char *str)
{
	int i;

	i = 0;
	if(!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	size_t	pos;
	size_t	neg;
	size_t	num;

	pos = 0;
	neg = 1;
	num = 0;
	if(!is_number(str))
		return (0);
	if (str[pos] == '-')
	{
		neg *= -1;
		pos++;
	}
	else if (str[pos] == '+')
		pos++;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10 + (str[pos] - '0');
		pos++;
	}
	num *= neg;
	return (num);
}
