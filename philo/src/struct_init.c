/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:12 by alex              #+#    #+#             */
/*   Updated: 2025/06/18 12:36:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosofers.h"

t_philo *struct_init(t_philo *aux, char *argv[])
{
    aux = (t_philo *)malloc(sizeof(t_philo));
    aux->philos = ft_atoi(argv[1]);
    aux->eattime = ft_atoi(argv[2]);
    aux->dietime = ft_atoi(argv[3]);
    aux->sleeptime = ft_atoi(argv[4]);
    aux->timestoeat = ft_atoi(argv[5]);
    return (aux);
}
