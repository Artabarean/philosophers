/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:46:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/27 11:30:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	philostart(t_aux *aux, t_philosopher *philos)
{
	int			i;
	pthread_t	*threads = malloc(sizeof(pthread_t) * aux->philosnum);

	i = 0;
	if (checkargv(aux) == 1)
		return (free(threads), 1);
	while (i < aux->philosnum)
	{
		philos[i].id = i + 1;
		philos[i].left_fork = &aux->forks[i];
		philos[i].right_fork = &aux->forks[(i + 1) % aux->philosnum];
		philos[i].aux = &aux;
		pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
	}
	
	return (0);
}

int	main(int argc, char *argv[])
{
	t_aux *aux;
	t_philosopher *philos;

	aux = NULL;
	philos = NULL;
	if (argc < 2 || argc > 6)
		return (argnum_check(), 0);
	aux = struct_init(aux, argv);
	if (aux == NULL)
		return (printf("Error:\none of the numbers is too large\n"));
	philos = philos_init(aux);
	if (philostart(aux, philos) == 1)
		return(free(philos), free(aux), 1);
	return (0);
}
