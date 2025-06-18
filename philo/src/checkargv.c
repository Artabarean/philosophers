/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:38:53 by alex              #+#    #+#             */
/*   Updated: 2025/06/18 12:44:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosofers.h"

int checkargv(t_philo *aux)
{
    if (aux->philos > 200)
        return (1);
    if (aux->dietime < aux->eattime || aux->dietime < 1 || aux->eattime < 1)
        return (1);
    if (aux->sleeptime < 1)
        return (1);
}
