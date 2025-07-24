/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:29:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/24 14:24:14 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    wait(t_philosopher *philo, long long tm, int *printed)
{
    printf("%lld %d is waiting\n", tm, philo->id);
    *printed = 1;
}

int	left_first(t_philosopher *philo, long long tm)
{
    int printed;

    printed = 0;
    while (philo->f1inuse == 1 || philo->f2inuse == 1)
    {
        if (printed == 0)
            wait(philo, tm, &printed);
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
    int printed;

    while (philo->f1inuse == 1 || philo->f2inuse == 1)
    {
        if (!printed)
        {
            printf("%lld %d is waiting\n", tm, philo->id);
            printed = 0;
            ft_usleep(100);
        }
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
