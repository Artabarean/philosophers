/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/19 10:28:40 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->aux->stop)
	{
		think(philo);
		pickforks(philo);
		eat(philo);
		put_fork_down(philo);
		philo_sleeps(philo);
	}
	return (NULL);
}
