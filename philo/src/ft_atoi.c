/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:05:08 by alex              #+#    #+#             */
/*   Updated: 2025/06/18 12:35:53 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosofers.h"

int ft_atoi(char *arg)
{
    int i;
    int num;
    int sign;
    
    i = 0;
    sign = 1;
    num = 0;
    while ((arg[i] == ' ' || arg[i] == '\t'))
        i++;
    while ((arg[i] == '-' || arg[i] == '+'))
    {
        if (arg[i] == '-')
            sign = -1;
        i++;
    }
    while (arg[i])
    {
        num = num * 10 + ((arg[i] - '0'));
        i++;
    }
    return (num * sign);
}
