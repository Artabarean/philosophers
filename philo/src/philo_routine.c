/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/30 11:06:35 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int check_death(t_philosopher *philo)
{
    int stop;

    pthread_mutex_lock(&philo->aux->deathofmutex);
    stop = philo->aux->stop;
    pthread_mutex_unlock(&philo->aux->deathofmutex);
    return (stop);
}

int check_deaths(t_philosopher *philos, int idx, int ttl)
{
    long long now;
    long long diff;

    if (idx == ttl)
        return (0);
    now = get_current_time();
    diff = now - philos[idx].last_meal_time;
    pthread_mutex_lock(&philos[idx].aux->deathofmutex);
    if (philos[idx].aux->stop == 0 && diff > philos[idx].aux->dietime)
    {
        philos[idx].aux->stop = 1;
        pthread_mutex_unlock(&philos[idx].aux->deathofmutex);
        pthread_mutex_lock(&philos[idx].aux->printofmutex);
        printf("%lld %d died💀\n", now - philos[idx].aux->start_time, philos[idx].id);
        pthread_mutex_unlock(&philos[idx].aux->printofmutex);
        return (1);
    }
    pthread_mutex_unlock(&philos[idx].aux->deathofmutex);
    return (check_deaths(philos, idx + 1, ttl));
}

void *monitor(void *arg)
{
    t_philosopher *philos;
    int total;
    
    philos = (t_philosopher *)arg;
    total = philos[0].aux->philosnum;
    while (1)
    {
        if (check_deaths(philos, 0, total))
            break;
        usleep(100);
    }
    return (NULL);
}

void	*philo_routine(void *arg)
{
    t_philosopher   *philo;

    philo = (t_philosopher *)arg;   
	philo->last_meal_time = philo->aux->start_time;    
    while (1)
    {
        if (check_death(philo))
            break;
        if (pickforks(philo) == -1)
            break;
        if (check_death(philo))
            break;
        eat(philo);
        philo->meals_eaten += 1;
        if (check_death(philo))
            break;
        put_down_fork(philo);
        if (philo->aux->mealnum && philo->meals_eaten == philo->aux->mealnum)
            return (has_eaten(philo), NULL);
        philo_sleeps(philo);
        if (check_death(philo))
            break;
        think(philo);
    }
    return (NULL);
}
