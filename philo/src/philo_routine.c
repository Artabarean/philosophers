/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/16 11:45:59 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int check_death(t_philosopher *philo)
{
    long long time;
    
    pthread_mutex_lock(&philo->aux->deathofmutex);
    if (philo->aux->stop == 1)
    {
        pthread_mutex_unlock(&philo->aux->deathofmutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->aux->deathofmutex);
    time = get_current_time();
    if (time - philo->last_meal_time > philo->aux->dietime)
    {
        pthread_mutex_lock(&philo->aux->deathofmutex);
        philo->aux->stop = 1;
        pthread_mutex_unlock(&philo->aux->deathofmutex);
        pthread_mutex_lock(&philo->aux->printofmutex);
        printf("%lld %d died\n", time - philo->aux->start_time, philo->id);
        pthread_mutex_unlock(&philo->aux->printofmutex);
        return (1);
    }
    return (0);
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
        think(philo);
        if (check_death(philo))
            break;
        if (pickforks(philo) == -1)
            break;
        eat(philo);
        put_down_fork(philo);
        if (philo->aux->mealnum != -1 && philo->meals_eaten >= philo->aux->mealnum)
            break;
        philo_sleeps(philo);
    }
    return (NULL);
}
