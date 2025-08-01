/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argnum_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:53:17 by atabarea          #+#    #+#             */
/*   Updated: 2025/08/01 12:27:42 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	argnum_check(void)
{
	write(1, "Error:\nthe number of arguments passed is invalid\n", 49);
}
