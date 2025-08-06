/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:31:35 by alex              #+#    #+#             */
/*   Updated: 2025/08/06 11:56:47 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	think(t_philosopher *philo)
{
	long long	tm;

	pthread_mutex_lock(&philo->aux->printofmutex);
	tm = get_current_time() - philo->aux->start_time;
	if (isdead(philo->aux) != 0)
		philo->aux->stop = 1;
	if (philo->aux->stop == 0)
		printf("%lld %d is thinking🤔\n", tm, philo->id);
	pthread_mutex_unlock(&philo->aux->printofmutex);
	usleep(100);
}

int	pickforks(t_philosopher *philo)
{
	long long	tm;

	tm = get_current_time() - philo->aux->start_time;
	if (philo->id % 2 == 0)
	{
		if (left_first(philo, tm) == 1 || right_first(philo, tm) == 1)
			return (-1);
	}
	else
	{
		if (right_first(philo, tm) == 1 || left_first(philo, tm) == 1)
			return (-1);
	}
	return (0);
}

int	eat(t_philosopher *philo)
{
	long long	tm;
	int			i;

	i = 0;
	pthread_mutex_lock(&philo->aux->printofmutex);
	philo->aux->stop = isdead(philo->aux);
	while (i < philo->aux->eattime)
	{
		ft_usleep(1);
		i++;
		if (isdead(philo->aux) != 0)
			return (pthread_mutex_unlock(&philo->aux->printofmutex), 1);
		if (i == philo->aux->eattime)
		{
			philo->last_meal_time = get_current_time();
			tm = philo->last_meal_time - philo->aux->start_time;
			printf("%lld %d is eating🍝\n", tm, philo->id);
		}
	}
	pthread_mutex_unlock(&philo->aux->printofmutex);
	philo->meals_eaten += 1;
	if (philo->aux->mealnum != -1 && philo->meals_eaten == philo->aux->mealnum)
		return (has_eaten(philo), 1);
	return (0);
}

void	put_down_fork(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->aux->fork_state_mutex);
	philo->aux->lfork_use[philo->id - 1] = 0;
	philo->aux->rfork_use[(philo->id) % philo->aux->philosnum] = 0;
	pthread_mutex_unlock(&philo->aux->fork_state_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	philo_sleeps(t_philosopher *philo)
{
	long long	tm;

	pthread_mutex_lock(&philo->aux->printofmutex);
	if (isdead(philo->aux) != 0)
		return (philo->aux->stop = 1);
	if (!check_death(philo))
		ft_usleep(philo->aux->sleeptime);
	tm = get_current_time() - philo->aux->start_time;
	if (philo->aux->stop == 0)
		printf("%lld %d sleeps💤\n", tm, philo->id);
	pthread_mutex_unlock(&philo->aux->printofmutex);
	return (0);
}
