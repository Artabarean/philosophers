/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_eaten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:54:49 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/30 11:00:50 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	has_eaten(t_philosopher *philo)
{
	long long	tm;

	tm = get_current_time() - philo->aux->start_time;
	printf("%lld %d has eaten all his meals🍗\n", tm,  philo->id);
}
