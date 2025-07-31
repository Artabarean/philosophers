/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdead.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:21:15 by alex              #+#    #+#             */
/*   Updated: 2025/07/31 12:31:39 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int isdead(t_aux *aux)
{
    int value;

    pthread_mutex_lock(&aux->dead);
    value = aux->death;
    pthread_mutex_unlock(&aux->dead);
    return (value);
}

void    set_death(t_aux *aux)
{
    pthread_mutex_lock(&aux->dead);
    aux->death = 1;
    pthread_mutex_unlock(&aux->dead);
}
