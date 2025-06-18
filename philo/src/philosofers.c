/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:46:10 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/18 12:36:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosofers.h"

void	philo(char *argv[], t_philo *aux)
{
	(void)argv;
	(void)aux;
}

int	main(int argc, char *argv[])
{
	t_philo *aux;

	aux = NULL;
	if (argc < 2 || argc > 6)
		return (argnum_check(), 0);
	struct_init(aux, argv);
	philo(argv, aux);
	return (0);
}
