/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forksinuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:09:23 by alex              #+#    #+#             */
/*   Updated: 2025/07/25 11:21:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int forksinuse(t_philosopher *philo)
{
    if (philo->f1inuse == 1 || philo->f2inuse == 1)
    {
        if (philo->id == 1 && get_current_time() - philo->aux->start_time == 0)
            return (0);
        else if (philo->id % 2 == 0)
            return (1);
    }
    return (0);
}
