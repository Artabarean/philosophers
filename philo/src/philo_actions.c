/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:31:35 by alex              #+#    #+#             */
/*   Updated: 2025/07/16 11:54:04 by atabarea         ###   ########.fr       */
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
    pthread_mutex_t *fst_fk;
    pthread_mutex_t *sd_fk;
    long long       tm;

    tm = get_current_time();
    if (philo->id % 2 == 0)
    {
        fst_fk = philo->left_fork;
        sd_fk = philo->right_fork;
    }
    else
    {
        fst_fk = philo->right_fork;
        sd_fk = philo->left_fork;
    }
    pthread_mutex_lock(fst_fk);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(fst_fk), -1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d took a fork\n", tm - philo->aux->start_time, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    pthread_mutex_lock(sd_fk);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(fst_fk), pthread_mutex_unlock(sd_fk), -1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    if (!philo->aux->stop)
        printf("%lld %d took a fork\n", tm - philo->aux->start_time, philo->id);
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
