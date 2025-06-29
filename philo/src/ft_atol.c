/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:05:08 by alex              #+#    #+#             */
/*   Updated: 2025/06/19 10:23:42 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	ft_atol(char *arg)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while ((arg[i] == ' ' || arg[i] == '\t'))
		i++;
	while ((arg[i] == '-' || arg[i] == '+'))
	{
		if (arg[i] == '-')
			return (-1);
		i++;
	}
	while (arg[i])
	{
		num = num * 10 + ((arg[i] - '0'));
		i++;
	}
	if (num > INT_MAX)
		return (-1);
	return (num);
}
