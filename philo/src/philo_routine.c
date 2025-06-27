/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/27 12:17:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_status(int stop, int i, char *str)
{
	if (stop == 1)
		return (1);
	else
	{
		if (str[0] == 't')
			printf("Philo[%d] thinks\n", i);
		if (str[0] == 'p')
			printf("Philo[%d] picks up a fork\n", i);
		if (str[0] == 'e')
			printf("Philo[%d] eats\n", i);
		if (str[0] == 'f')
			printf("Philo[%d] puts down the fork\n", i);
		if (str[0] == 's')
			printf("Philo[%d] sleeps\n", i);
	}
	return (0);		
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;
	int				i;
	
	i = 0;
	philo = (t_philosopher *)arg;
	while (!philo->aux->stop)
	{
		think(philo, i);
		if (check_status(philo->aux->stop, i, "think") == 1)
			break ;
		pickforks(philo);
		if (check_status(philo->aux->stop, i, "pickfork") == 1)
			break ;
		eat(philo);
		if (check_status(philo->aux->stop, i, "eat") == 1)
			break ;
		put_fork_down(philo);
		if (check_status(philo->aux->stop, i, "forkdown") == 1)
			break ;
		philo_sleeps(philo);
		if (check_status(philo->aux->stop, i, "sleep") == 1)
			break ;
		i++;
	}
	return (NULL);
}
