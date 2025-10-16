/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:38:53 by alex              #+#    #+#             */
/*   Updated: 2025/10/16 12:26:19 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (1);
	else
		return (0);
}

int	checkdigit(char *argv[])
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (is_digit(argv[j][i]) == 1)
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}

int	checkargv(char *argv[])
{
	if (checkdigit(argv) == 1)
		return (1);
	if (ft_atol(argv[1]) > 200)
		return (1);
	if (ft_atol(argv[2]) < ft_atol(argv[3]) || ft_atol(argv[2]) < 1
		|| ft_atol(argv[3]) < 1)
		return (1);
	if (ft_atol(argv[4]) < 1)
		return (1);
	return (0);
}
