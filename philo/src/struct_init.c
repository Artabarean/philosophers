/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:11:12 by alex              #+#    #+#             */
/*   Updated: 2025/06/18 13:17:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosofers.h"

int zeros_in_int(char **a)
{
    int     i;
    int     k;
    int     j;

    i = 1;
    while (a[i])
    {
        k = 0;
            j = 0;
        while (a[i][j])
            j++;
        while (a[i][k] == '0' || a[i][k] == '-')
            k++;
        if (j > (k + 11))
            return (1);
        else
            break ;
        i++;
    }
    return (0);
}

int     max_min_int(char **arg)
{
    int     i;
    int     j;
    int     k;

    i = 1;
    while (arg[i])
    {
        j = 0;
        k = 0;
        while (arg[i][j])
        {
            while (arg[i][k])
                k++;
            if (k > 11 && zeros_in_int(arg) == 1)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


t_philo *struct_init(t_philo *aux, char *argv[])
{
    aux = (t_philo *)malloc(sizeof(t_philo));
    aux->philos = ft_atol(argv[1]);
    aux->eattime = ft_atol(argv[2]);
    aux->dietime = ft_atol(argv[3]);
    aux->sleeptime = ft_atol(argv[4]);
    aux->timestoeat = ft_atol(argv[5]);
    if (aux->philos == -1 || aux->eattime == -1 || aux->sleeptime == -1
        || aux->dietime == -1 || aux->timestoeat == -1)
        return (aux = NULL);
    if (max_min_int(argv) == 1)
        return (aux = NULL);
    return (aux);
}
