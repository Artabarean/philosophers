/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/08/04 15:13:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_death(t_philosopher *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->aux->deathofmutex);
	stop = philo->aux->stop;
	pthread_mutex_unlock(&philo->aux->deathofmutex);
	return (stop);
}

int	check_deaths(t_philosopher *philo, int idx, int ttl)
{
	long long	now;
	long long	diff;

	if (idx == ttl)
		return (0);
	now = get_current_time();
	diff = now - philo[idx].last_meal_time;
	pthread_mutex_lock(&philo[idx].aux->deathofmutex);
	if (philo[idx].aux->stop == 0 && diff > philo[idx].aux->dietime)
	{
		set_death(philo->aux);
		philo[idx].aux->stop = 1;
		pthread_mutex_unlock(&philo[idx].aux->deathofmutex);
		pthread_mutex_lock(&philo[idx].aux->printofmutex);
		printf("%lld %d died💀\n", now - philo[idx].aux->start_time,
			philo[idx].id);
		pthread_mutex_unlock(&philo[idx].aux->printofmutex);
		return (1);
	}
	if (philo->aux->stop == 1)
		return (pthread_mutex_unlock(&philo[idx].aux->deathofmutex), 1);
	pthread_mutex_unlock(&philo[idx].aux->deathofmutex);
	return (check_deaths(philo, idx + 1, ttl));
}

void	*monitor(void *arg)
{
	t_philosopher	*philo;
	int				ttl;

	philo = (t_philosopher *)arg;
	ttl = philo[0].aux->philosnum;
	while (1)
	{
		if (check_deaths(philo, 0, ttl) == 1)
			break ;
		if (philo->aux->mealnum != -1)
		{
			if (all_philos_done(philo, ttl))
			{
				pthread_mutex_lock(&philo[0].aux->deathofmutex);
				philo[0].aux->stop = 1;
				pthread_mutex_unlock(&philo[0].aux->deathofmutex);
				usleep(1000);
				printf("simulation has ended 😁\n");
				break ;
			}
		}
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->last_meal_time = philo->aux->start_time;
	while (1)
	{
		if (pickforks(philo) == -1)
			break ;
		if (check_death(philo) != 0)
			break ;
		eat(philo);
		if (check_death(philo) != 0)
			break ;
		put_down_fork(philo);
		if (philo->aux->mealnum != -1
			&& philo->meals_eaten == philo->aux->mealnum)
			return (has_eaten(philo), NULL);
		philo_sleeps(philo);
		if (check_death(philo) != 0)
			break ;
		think(philo);
		if (check_death(philo) != 0)
			break ;
	}
	return (NULL);
}
