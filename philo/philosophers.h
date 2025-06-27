/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:45:52 by atabarea          #+#    #+#             */
/*   Updated: 2025/06/27 11:43:48 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>

typedef struct s_aux
{
	int				philosnum;
	int				dietime;
	int				sleeptime;
	int				eattime;
    int 			mealnum;
	int				death;
	int				stop;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printofmutex;
	pthread_mutex_t deathofmutex;
}               t_aux;

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	long long		last_meal_time;
	int				meals_eaten;
	t_aux			*aux;
}			t_philosopher;

void    think(t_philosopher *philo, int i);
void	argnum_check(void);
void	*philo_routine(void *arg);
t_aux 	*struct_init(t_aux *aux, char *argv[]);
long 	ft_atol(char *arg);
int		philostart(t_aux *aux, t_philosopher *philos);
int 	checkargv(t_aux *aux);

#endif