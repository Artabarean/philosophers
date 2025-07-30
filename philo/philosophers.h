/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:45:52 by atabarea          #+#    #+#             */
/*   Updated: 2025/07/30 11:17:00 by atabarea         ###   ########.fr       */
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
	int				*fork_use;
	int				stop;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t fork_state_mutex;
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
void			has_eaten(t_philosopher *philo);
void    		put_down_fork(t_philosopher *philo);
void    		philo_sleeps(t_philosopher *philo);
void			argnum_check(void);
int 			check_deaths(t_philosopher *philos, int index, int total);
int				right_first(t_philosopher *philo, long long tm);
int				left_first(t_philosopher *philo, long long tm);
void			*philo_routine(void *arg);
long long   	get_current_time(void);
void 			*monitor(void *arg);
void 			ft_usleep(int condition);
t_aux 			*struct_init(t_aux *aux, char *argv[], int argc);
long 			ft_atol(char *arg);
t_philosopher	*philos_init(t_aux *aux);
int				philostart(t_aux *aux, t_philosopher *philos);
int 			checkargv(t_aux *aux);
int 			all_philos_done(t_philosopher *philos, int total);
int 			zeros_in_int(char **a);
int     		max_min_int(char **arg);
int 			check_death(t_philosopher *philo);
void    		put_down_fork(t_philosopher *philo);
void		    philo_sleeps(t_philosopher *philo);

#endif