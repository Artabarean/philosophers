/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:29:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/25 11:23:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    wait(t_philosopher *philo, long long tm)
{
    printf("%lld %d is waiting\n", tm, philo->id);
    while (1)
    {
        if (philo->f1inuse == 0 || philo->f2inuse == 0)
            break;
    }
}

int	left_first(t_philosopher *philo, long long tm)
{
    if (forksinuse(philo) == 1)
    {
        wait(philo, tm);
    }
	pthread_mutex_lock(philo->left_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->left_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    philo->f1inuse = 1;
    pthread_mutex_lock(philo->right_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->right_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    philo->f2inuse = 1;
    return (0);
}

int	right_first(t_philosopher *philo, long long tm)
{
    if (forksinuse(philo) == 1)
    {
        wait(philo, tm);
    }
	pthread_mutex_lock(philo->right_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->right_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    philo->f1inuse = 1;
    pthread_mutex_lock(philo->left_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->left_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    philo->f2inuse = 1;
    return (0);
}
