/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:29:09 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/30 11:05:38 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    wait(t_philosopher *philo, long long tm)
{
    tm = get_current_time() - philo->aux->start_time;
    printf("%lld %d is waiting⏳\n", tm, philo->id);
}

int	left_first(t_philosopher *philo, long long tm)
{
    pthread_mutex_lock(&philo->aux->fork_state_mutex);
    if (philo->aux->fork_use[philo->id - 1] == 1)
        wait(philo, tm);
    pthread_mutex_unlock(&philo->aux->fork_state_mutex);
    pthread_mutex_lock(philo->left_fork);
    pthread_mutex_lock(&philo->aux->fork_state_mutex);
    philo->aux->fork_use[philo->id - 1] = 1;
    pthread_mutex_unlock(&philo->aux->fork_state_mutex);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->left_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    tm = get_current_time() - philo->aux->start_time;
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork🍴\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    return (0);
}

int	right_first(t_philosopher *philo, long long tm)
{
    int right_idx;

    right_idx = (philo->id) % philo->aux->philosnum;
    pthread_mutex_lock(&philo->aux->fork_state_mutex);
    if (philo->aux->fork_use[right_idx] == 1)
        wait(philo, tm);
    pthread_mutex_unlock(&philo->aux->fork_state_mutex);
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_lock(&philo->aux->fork_state_mutex);
    philo->aux->fork_use[philo->id - 1] = 1;
    pthread_mutex_unlock(&philo->aux->fork_state_mutex);
    if (philo->aux->stop)
        return (pthread_mutex_unlock(philo->right_fork), 1);
    pthread_mutex_lock(&philo->aux->printofmutex);
    tm = get_current_time() - philo->aux->start_time;
    if (!philo->aux->stop)
        printf("%lld %d has taken a fork🍴\n", tm, philo->id);
    pthread_mutex_unlock(&philo->aux->printofmutex);
    return (0);
}
