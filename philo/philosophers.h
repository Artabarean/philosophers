/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:45:52 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/15 12:13:37 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

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

void    		think(t_philosopher *philo);
int 			pickforks(t_philosopher *philo);
void    		eat(t_philosopher *philo);
void    		put_down_fork(t_philosopher *philo);
void    		philo_sleeps(t_philosopher *philo);
void			argnum_check(void);
void			*philo_routine(t_philosopher *philo);
long long   	get_current_time(void);
t_aux 			*struct_init(t_aux *aux, char *argv[], int argc);
long 			ft_atol(char *arg);
t_philosopher	*philos_init(t_aux *aux);
int				philostart(t_aux *aux, t_philosopher *philos);
int 			checkargv(t_aux *aux);
int 			zeros_in_int(char **a);
int     		max_min_int(char **arg);
int 			check_death(t_philosopher *philo);
void    		put_down_fork(t_philosopher *philo);
void		    philo_sleeps(t_philosopher *philo);

#endif