/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:31:35 by alex              #+#    #+#             */
/*   Updated: 2025/07/24 11:35:58 by atabarea         ###   ########.fr       */
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
    long long       tm;

    tm = get_current_time() - philo->aux->start_time;
    if (philo->id % 2 == 0)
    {
        if (left_first(philo, tm) == 1)
        return (-1);
    }
    else
    {
        if (right_first(philo, tm) == 1)
        return (-1);
    }
    return (0);
}

void    eat(t_philosopher *philo)
{
    long long   tm;

    tm = get_current_time() - philo->aux->start_time;    
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d is eating\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}

void    put_down_fork(t_philosopher *philo)
{
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    philo_sleeps(t_philosopher *philo)
{
    long long   tm;

    ft_usleep(200);
    tm = get_current_time() - philo->aux->start_time;
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d sleeps\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
}
