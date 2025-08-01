/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:46:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/08/01 12:27:09 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	philostart(t_aux *aux, t_philosopher *philos)
{
	int			i;
	pthread_t	*thds;
	pthread_t	monitor_thread;

	i = 0;
	thds = malloc(sizeof(pthread_t) * aux->philosnum);
	while (i < aux->philosnum)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &aux->forks[i];
		philos[i].right_fork = &aux->forks[(i + 1) % aux->philosnum];
		philos[i].aux = aux;
		pthread_create(&thds[i], NULL, philo_routine, &philos[i]);
		usleep(100);
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor, (void *)philos);
	i = 0;
	while (i < aux->philosnum)
	{
		pthread_join(thds[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	return (free(thds), 0);
}

int	main(int argc, char *argv[])
{
	t_aux			*aux;
	t_philosopher	*philos;

	aux = NULL;
	philos = NULL;
	if (argc < 5 || argc > 6)
		return (argnum_check(), 1);
	aux = struct_init(aux, argv, argc);
	if (aux == NULL)
		return (printf("Error:\none of the numbers is too large\n"));
	philos = philos_init(aux);
	philos->meals_eaten = 0;
	aux->stop = 0;
	if (checkargv(aux) == 1)
	{
		printf("Arguments passed are invalid\n");
		return (free(philos), free(aux), 1);
	}
	if (philostart(aux, philos) == 1)
		return (free(philos), free(aux), 1);
	return (0);
}
