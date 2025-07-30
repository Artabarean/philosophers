/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_eaten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:54:49 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/30 11:50:42 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	has_eaten(t_philosopher *philo)
{
	long long	tm;

	tm = get_current_time() - philo->aux->start_time;
	printf("%lld %d has eaten all his meals🍗\n", tm,  philo->id);
}

int all_philos_done(t_philosopher *philo, int ttl)
{
    int i;

    if (philo[0].aux->mealnum == -1)
        return (0);
    i = 0;
    while (i < ttl)
    {
        if (philo[i].meals_eaten < philo[0].aux->mealnum)
            return (0);
        i++;
    }
    return (1);
}
