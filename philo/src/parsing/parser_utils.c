/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/01/19 17:00:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	unsigned int		pos;
	unsigned long long	num;

	pos = 0;
	num = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10 + (str[pos] - '0');
		pos++;
	}
	if (num > INT_MAX)
		return (-1);
	return ((int)num);
}
