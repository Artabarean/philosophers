/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:29:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/24 11:36:20 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	left_first(t_philosopher *philo, long long tm)
{
	pthread_mutex_lock(philo->left_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->left_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    pthread_mutex_lock(philo->right_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->right_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    return (0);
}

int	right_first(t_philosopher *philo, long long tm)
{
	pthread_mutex_lock(philo->right_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->right_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    pthread_mutex_lock(philo->left_fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->left_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    return (0);
}
