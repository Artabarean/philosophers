/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:29:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/10 13:02:55 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	wait(t_philosopher *philo)
{
	if (philo->id < philo->aux->philosnum)
	{
		if (isdead(philo->aux) != 0)
			return ;
		while (philo->aux->lfork_use[philo->id - 1] == 1 &&
			philo->aux->rfork_use[philo->id] == 1)
		{
			ft_usleep(1);
		}
	}
	else
	{
		if (isdead(philo->aux) != 0)
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
	pthread_mutex_lock(philo->right_fork);
	if (philo->aux->rfork_use[philo->id] == 1)
	philo->aux->lfork_use[philo->id - 1] = 0;
	//to be done digger
	pthread_mutex_unlock(&philo->aux->printofmutex);
	if (isdead(philo->aux) != 0)
		return (pthread_mutex_unlock(philo->left_fork), 1);
	pthread_mutex_lock(&philo->aux->printofmutex);
	tm = get_current_time() - philo->aux->start_time;
	printf("%lld %d has taken a fork🍴\n", tm, philo->id);
	pthread_mutex_unlock(&philo->aux->printofmutex);
	return (0);
}

int	right_first(t_philosopher *philo, long long tm)
{
	if (isdead(philo->aux) != 0)
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
	if (isdead(philo->aux) != 0)
		return (pthread_mutex_unlock(philo->right_fork), 1);
	pthread_mutex_lock(&philo->aux->printofmutex);
	tm = get_current_time() - philo->aux->start_time;
	printf("%lld %d has taken a fork🍴\n", tm, philo->id);
	pthread_mutex_unlock(&philo->aux->printofmutex);
	return (0);
}
