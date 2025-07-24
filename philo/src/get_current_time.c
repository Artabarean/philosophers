/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:36:14 by alex              #+#    #+#             */
/*   Updated: 2025/07/24 11:21:59 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long   get_current_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

void ft_usleep(int condition)
{
    long start;
    long elapsed;
    
    start = get_current_time();
    if (condition > 1)
        usleep((condition - 1) * 1000);
    while ((elapsed = get_current_time() - start) < condition)
        usleep(100);
}
