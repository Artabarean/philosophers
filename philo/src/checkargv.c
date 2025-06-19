/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:38:53 by alex              #+#    #+#             */
/*   Updated: 2025/06/19 10:23:46 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int checkargv(t_aux *aux)
{
    if (aux->philosnum > 200)
        return (1);
    if (aux->dietime < aux->eattime || aux->dietime < 1 || aux->eattime < 1)
        return (1);
    if (aux->sleeptime < 1)
        return (1);
    return (0);
}
