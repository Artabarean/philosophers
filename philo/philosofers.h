/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:45:52 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/18 12:31:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_philo
{
	int	philos;
	int	dietime;
	int	sleeptime;
	int	eattime;
    int timestoeat;
}               t_philo;

void	argnum_check(void);
t_philo *struct_init(t_philo *aux, char *argv[]);
int 	ft_atoi(char *arg);

#endif