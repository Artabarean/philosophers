/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:12 by alex              #+#    #+#             */
/*   Updated: 2025/10/10 11:26:46 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	forkation(t_aux *aux)
{
	int	i;

	i = 0;
	while (i < aux->philosnum)
	{
		aux->lfork_use[i] = 0;
		aux->rfork_use[i] = 0;
		i++;
	}
}

int	zeros_in_int(char **a)
{
	int	i;
	int	k;
	int	j;

	i = 1;
	while (a[i])
	{
		k = 0;
		j = 0;
		while (a[i][j])
			j++;
		while (a[i][k] == '0' || a[i][k] == '-')
			k++;
		if (j > (k + 11))
			return (1);
		else
			break ;
		i++;
	}
	return (0);
}

int	max_min_int(char **arg)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (arg[i])
	{
		j = 0;
		k = 0;
		while (arg[i][j])
		{
			while (arg[i][k])
				k++;
			if (k > 11 && zeros_in_int(arg) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_aux	*struct_init(t_aux *aux, char *argv[], int argc)
{
	aux = (t_aux *)malloc(sizeof(t_aux));
	aux->philosnum = ft_atol(argv[1]);
	aux->dietime = ft_atol(argv[2]);
	aux->eattime = ft_atol(argv[3]);
	aux->sleeptime = ft_atol(argv[4]);
	aux->start_time = get_current_time();
	aux->forks = malloc(sizeof(pthread_mutex_t) * aux->philosnum);
	aux->lfork_use = malloc(sizeof(int) * aux->philosnum);
	aux->rfork_use = malloc(sizeof(int) * aux->philosnum);
	aux->death = 0;
	aux->eated = 0;
	forkation(aux);
	if (argc == 6)
		aux->mealnum = ft_atol(argv[5]);
	else
		aux->mealnum = -1;
	if (aux->philosnum == -1 || aux->eattime == -1 || aux->sleeptime == -1
		|| aux->dietime == -1)
		return (aux = NULL);
	if (max_min_int(argv) == 1)
		return (aux = NULL);
	return (aux);
}
