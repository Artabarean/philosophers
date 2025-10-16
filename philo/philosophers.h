/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:45:52 by atabarea          #+#    #+#             */
/*   Updated: 2025/10/16 11:41:33 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_aux
{
	int				philosnum;
	int				dietime;
	int				sleeptime;
	int				eattime;
	int				eated;
	int				mealnum;
	int				death;
	int				*lfork_use;
	int				*rfork_use;
	long long		start_time;
	int				stop;
	pthread_mutex_t	mealprt;
	pthread_mutex_t	eaten;
	pthread_mutex_t	mealtimeprot;
	pthread_mutex_t	dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printofmutex;
	pthread_mutex_t	deathofmutex;
}					t_aux;

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_meal_time;
	int				meals_eaten;
	t_aux			*aux;
}					t_philosopher;

void				think(t_philosopher *philo);
int					isdead(t_aux *aux);
void				set_death(t_aux *aux);
int					pickforks(t_philosopher *philo);
int					eat(t_philosopher *philo);
void				freestuff(t_aux *aux);
void				eaten(t_philosopher *philo);
void				put_down_fork(t_philosopher *philo);
int					philo_sleeps(t_philosopher *philo);
void				argnum_check(void);
int					check_deaths(t_philosopher *philos, int index, int total);
int					right_first(t_philosopher *philo, long long tm);
int					left_first(t_philosopher *philo, long long tm);
void				*philo_routine(void *arg);
long long			get_current_time(void);
void				*monitor(void *arg);
void				ft_usleep(int condition);
t_aux				*struct_init(t_aux *aux, char *argv[], int argc);
long				ft_atol(char *arg);
t_philosopher		*philos_init(t_aux *aux);
int					philostart(t_aux *aux, t_philosopher *philos);
int					checkargv(char *argv[]);
int					all_philos_done(t_philosopher *philos, int total);
int					zeros_in_int(char **a);
int					max_min_int(char **arg);
void				put_down_fork(t_philosopher *philo);

#endif