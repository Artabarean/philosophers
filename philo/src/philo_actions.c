/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:31:35 by alex              #+#    #+#             */
/*   Updated: 2025/07/14 16:17:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    think(t_philosopher *philo)
{
    long long   tm;

    tm = get_current_time();
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d is thinking\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    
}

int pickforks(t_philosopher *philo)
{
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;
    long long       tm;

    tm = get_current_time();
    if (philo->id % 2 == 0)
    {
        first_fork = philo->left_fork;
        second_fork = philo->right_fork;
    }
    else
    {
        first_fork = philo->right_fork;
        second_fork = philo->left_fork;
    }
    pthread_mutex_lock(first_fork);
    if (philo->aux->stop)
    {
        pthread_mutex_lock(first_fork);
        return (-1);
    }
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    pthread_mutex_lock(second_fork);
    if (philo->aux->stop)
    {
        pthread_mutex_unlock(first_fork);
        pthread_mutex_unlock(second_fork);
        return (-1);
    }
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    return (0);
    
}

void    eat(t_philosopher *philo)
{
    long long   tm;

    tm = get_current_time();    
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d is eating\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}

void    put_down_fork(t_philosopher *philo)
{
    long long   tm;

    tm = get_current_time();
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d puts down both forks\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}

void    philo_sleeps(t_philosopher *philo)
{
    long long   tm;

    tm = get_current_time();
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d sleeps\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}
