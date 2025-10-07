/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/07 13:02:47 by atabarea         ###   ########.fr       */
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
	pthread_mutex_lock(&philo[idx].aux->deathofmutex);
	now = get_current_time();
	diff = now - philo[idx].last_meal_time;
	if (philo[idx].aux->stop == 0 && diff > philo[idx].aux->dietime
		&& philo[idx].aux->eated == 0)
	{
		set_death(philo->aux);
		philo[idx].aux->stop = 1;
		now = get_current_time();
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
				ft_usleep(50);
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
		if (check_death(philo) != 0)
			return (NULL);
		if (pickforks(philo) == -1)
			return (put_down_fork(philo), NULL);
		if (check_death(philo) != 0)
			return (put_down_fork(philo), NULL);
		if (eat(philo) == 1)
			return (put_down_fork(philo), NULL);
		if (check_death(philo) != 0)
			return (put_down_fork(philo), NULL);
		put_down_fork(philo);
		if (philo_sleeps(philo) == 1)
			return (NULL);
		if (check_death(philo) != 0)
			return (NULL);
		think(philo);
		if (check_death(philo) != 0)
			return (NULL);
	}
}
