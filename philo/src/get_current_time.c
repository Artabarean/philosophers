/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:36:14 by alex              #+#    #+#             */
/*   Updated: 2025/07/17 10:33:45 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long   get_current_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000);
}
long long   get_elapsed_tm(void)
{
    static long long   start_tm = 0;

    if (start_tm == 0)
        start_tm = get_current_time();
    return (get_current_time() - start_tm);
}
