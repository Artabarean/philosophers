/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argnum_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:53:17 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/28 14:03:17 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	argnum_check(void)
{
	write(1, "Error:\nthe number of arguments passed is invalid\n", 49);	
}
