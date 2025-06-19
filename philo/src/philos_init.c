/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:59:30 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/19 10:25:58 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philosopher	*philos_init(t_aux *aux)
{
	t_philosopher *philos;
	
	philos = malloc(sizeof(t_philosopher) * aux->philosnum);
	return (philos);
}
