/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:31:35 by alex              #+#    #+#             */
/*   Updated: 2025/06/27 11:44:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    think(t_philosopher *philo, int i)
{
    philo->aux->dietime -= 1;
    if (philo->aux->dietime == 0)
    {
        philo->aux->stop = 1;
        printf("philo[%d] dies", i);
        return ;
    }
}
