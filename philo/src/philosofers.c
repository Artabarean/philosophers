/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:46:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/18 13:19:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosofers.h"

int	philo(t_philo *aux)
{
	if (checkargv(aux) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_philo *aux;

	aux = NULL;
	if (argc < 2 || argc > 6)
		return (argnum_check(), 0);
	aux = struct_init(aux, argv);
	if (aux == NULL)
		return (printf("Error:\none of the numbers is too big\n"));
	if (philo(aux) == 1)
		return(1);
	return (0);
}
