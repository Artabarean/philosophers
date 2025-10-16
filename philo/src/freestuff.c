/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freestuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:34:30 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/16 11:30:06 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	freestuff(t_aux *aux)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&aux->mealprt);
	pthread_mutex_destroy(&aux->mealtimeprot);
	pthread_mutex_destroy(&aux->eaten);
	pthread_mutex_destroy(&aux->dead);
	pthread_mutex_destroy(&aux->printofmutex);
	pthread_mutex_destroy(&aux->deathofmutex);
	while (i < aux->philosnum)
	{
		pthread_mutex_destroy(&aux->forks[i]);
		i++;
	}
	free(aux->forks);
	free(aux->lfork_use);
	free(aux->rfork_use);
}
