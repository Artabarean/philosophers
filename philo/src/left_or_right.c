/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:29:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/09 10:24:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	wait(t_philosopher *philo)
{
	// long long tm;

	// tm = get_current_time() - philo->aux->start_time;
	// printf("%lld %d is waiting⏳\n", tm, philo->id);
	if (philo->id < philo->aux->philosnum)
	{
		if (check_death(philo) != 0)
			return ;
		while (philo->aux->lfork_use[philo->id - 1] == 1 &&
			philo->aux->rfork_use[philo->id] == 1)
		{
			ft_usleep(1);
		}
	}
	else
	{
		if (check_death(philo) != 0)
			return ;
		while (philo->aux->lfork_use[philo->id - 1] == 1 &&
			philo->aux->rfork_use[0] == 1)
		{
			ft_usleep(1);
		}
	}
}

int	left_first(t_philosopher *philo, long long tm)
{
	if (check_death(philo) != 0)
		return (1);
	if (philo->id < philo->aux->philosnum)
	{
		if (philo->aux->lfork_use[philo->id - 1] == 1 &&
		philo->aux->rfork_use[philo->id] == 1)
			wait(philo);
	}
	else
	{
		if (philo->aux->lfork_use[philo->id - 1] == 1 &&
		philo->aux->rfork_use[0] == 1)
			wait(philo);
	}
	pthread_mutex_lock(philo->left_fork);
	philo->aux->lfork_use[philo->id - 1] = 1;
	if (check_death(philo) != 0)
		return (pthread_mutex_unlock(philo->left_fork), 1);
	pthread_mutex_lock(&philo->aux->printofmutex);
	tm = get_current_time() - philo->aux->start_time;
	printf("%lld %d has taken a fork🍴\n", tm, philo->id);
	// if (philo->aux->stop == 0)
	// 	printf("%lld %d has taken fork nº: %d🍴\n", tm, philo->id, (philo->id - 1));
	pthread_mutex_unlock(&philo->aux->printofmutex);
	return (0);
}

int	right_first(t_philosopher *philo, long long tm)
{
	
	if (check_death(philo) != 0)
		return (1);
	if (philo->id < philo->aux->philosnum)
	{
		if (philo->aux->lfork_use[philo->id - 1] == 1 &&
		philo->aux->rfork_use[philo->id] == 1)
			wait(philo);
	}
	else
	{
		if (philo->aux->lfork_use[philo->id + 1] == 1 &&
		philo->aux->rfork_use[0] == 1)
			wait(philo);
	}
	pthread_mutex_lock(philo->right_fork);
	philo->aux->rfork_use[philo->id] = 1;
	if (check_death(philo) != 0)
		return (pthread_mutex_unlock(philo->right_fork), 1);
	pthread_mutex_lock(&philo->aux->printofmutex);
	tm = get_current_time() - philo->aux->start_time;
	printf("%lld %d has taken a fork🍴\n", tm, philo->id);
	// if (philo->aux->stop == 0)
	// {
	// 	if (philo->id< philo->aux->philosnum)
	// 		printf("%lld %d has taken fork nº: %d🍴\n", tm, philo->id, philo->id);
	// 	else
	// 		printf("%lld %d has taken fork nº: 0🍴\n", tm, philo->id);
	// }
	pthread_mutex_unlock(&philo->aux->printofmutex);
	return (0);
}
