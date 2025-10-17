/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:46:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/17 10:49:14 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	jointhreads(t_aux *aux, pthread_t *thds)
{
	int	i;

	i = 0;
	while (i < aux->philosnum)
	{
		pthread_join(thds[i], NULL);
		i++;
	}
}

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
		if ((i + 1) >= aux->philosnum && aux->philosnum > 1)
			philos[i].right_fork = &aux->forks[0];
		else if ((i + 1) < aux->philosnum && aux->philosnum > 1)
			philos[i].right_fork = &aux->forks[(i + 1)];
		philos[i].aux = aux;
		pthread_create(&thds[i], NULL, philo_routine, &philos[i]);
		i++;
		usleep(10);
	}
	pthread_create(&monitor_thread, NULL, monitor, (void *)philos);
	jointhreads(aux, thds);
	freestuff(philos->aux);
	pthread_join(monitor_thread, NULL);
	printf("simulation has ended 😁\n");
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
	if (checkargv(argv) == 1)
	{
		printf("Error:\nArguments passed are invalid\n");
		return (1);
	}
	if (argc > 5 && ft_atol(argv[5]) <= 0)
		return (printf("Error:\nPhilosophers can't eat 0 or less times\n"), 1);
	aux = struct_init(aux, argv, argc);
	if (aux == NULL)
		return (printf("Error:\nOne of the numbers is too large\n"), 1);
	philos = philos_init(aux);
	philos->meals_eaten = 0;
	aux->stop = 0;
	philostart(aux, philos);
	free(philos);
	free(aux);
	return (0);
}
