/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:31:35 by alex              #+#    #+#             */
/*   Updated: 2025/07/22 13:00:14 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void think(t_philosopher *philo)
{
    long long tm;

    ft_usleep(100);
    tm = get_current_time() - philo->aux->start_time;
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d is thinking\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}

int pickforks(t_philosopher *philo)
{
    pthread_mutex_t *fork;
    long long       tm;

    tm = get_current_time() - philo->aux->start_time;
    if (philo->id % 2 == 0)
        fork = philo->left_fork;
    else
        fork = philo->right_fork;
    pthread_mutex_lock(fork);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(fork), -1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d picked up a fork\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    return (0);
}

void    eat(t_philosopher *philo)
{
    long long   tm;

    ft_usleep(100);
    tm = get_current_time() - philo->aux->start_time;    
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d is eating\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}

void    put_down_fork(t_philosopher *philo)
{
    long long   tm;

    ft_usleep(100);
    tm = get_current_time() - philo->aux->start_time;
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d puts down both forks\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}

void    philo_sleeps(t_philosopher *philo)
{
    long long   tm;

    ft_usleep(100);
    tm = get_current_time() - philo->aux->start_time;
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d sleeps\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}
