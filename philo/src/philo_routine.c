/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:20:08 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/10 12:44:07 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	diffcalc(t_philosopher *philo, int idx)
{
	long long	now;
	long long	diff;

	pthread_mutex_lock(&philo->aux->mealtimeprot);
	now = get_current_time();
	diff = now - philo[idx].last_meal_time;
	pthread_mutex_unlock(&philo->aux->mealtimeprot);
	return (diff);
}

int	check_deaths(t_philosopher *philo, int idx,int ttl)
{
	long long	now;
	long long	diff;

	if (idx == ttl)
		return (0);
	pthread_mutex_lock(&philo[idx].aux->deathofmutex);
	diff = diffcalc(philo, idx);
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
	pthread_mutex_unlock(&philo[idx].aux->deathofmutex);
	if (philo[idx].aux->stop == 1)
		return (1);
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
		pthread_mutex_lock(&philo->aux->mealprt);
		if (philo->aux->mealnum != -1)
			if (all_philos_done(philo, ttl))
			{
				pthread_mutex_unlock(&philo->aux->mealprt);
				pthread_mutex_lock(&philo[0].aux->deathofmutex);
				philo[0].aux->stop = 1;
				pthread_mutex_unlock(&philo[0].aux->deathofmutex);
				ft_usleep(50);
				printf("simulation has ended 😁\n");
				break ;
			}
		pthread_mutex_unlock(&philo->aux->mealprt);
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(&philo->aux->mealtimeprot);
	philo->last_meal_time = philo->aux->start_time;
	pthread_mutex_unlock(&philo->aux->mealtimeprot);
	while (1)
	{
		if (isdead(philo->aux) != 0)
			return (NULL);
		if (pickforks(philo) == -1)
			return(NULL);
		if (isdead(philo->aux) != 0)
			return (put_down_fork(philo), NULL);
		if (eat(philo) == 1)
			return (put_down_fork(philo), NULL);
		if (isdead(philo->aux) != 0)
			return (put_down_fork(philo), NULL);
		put_down_fork(philo);
		if (philo_sleeps(philo) == 1)
			return (NULL);
		if (isdead(philo->aux) != 0)
			return (NULL);
		think(philo);
		if (isdead(philo->aux) != 0)
			return (NULL);
	}
}
