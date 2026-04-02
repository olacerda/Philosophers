/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:24 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 14:59:57 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

# define FAIL -1
# define UL unsigned long

typedef struct timeval t_time;
typedef pthread_mutex_t t_mutex;
typedef pthread_t		t_thread;

typedef enum	s_log
{
	TAKEN_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	DIED
}				t_log;

typedef enum s_arg
{
	PHILO_COUNT = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	EAT_COUNT = 5,
}			t_arg;

typedef struct s_params
{
	long		philo_count;
	long		death_time;
	long		eat_time;
	long		sleep_time;
	long		eat_count;
	long		start_time;
}			t_params;


typedef struct s_philo
{
	int			id;
	UL			*last_meal;
	UL			time_to_awake;
	t_mutex		*check_meal;
	t_mutex		*right_hand;
	t_mutex		*left_hand;
	t_arg		message;
	t_mutex		*check_message;
	t_all		*all;
}				t_philo;

typedef struct s_actions
{
	int	(*safe)(t_mutex *mutex, t_philo *philo, t_all *all, int function(t_all *all, t_philo *philo, void *arg));
	int	(*is_dead)(t_all *all, t_philo *philo);
	int	(*have_to_stop)(t_all *all, t_philo *philo);
	int	(*stop)(t_all *all, t_philo *philo);
	int	(*print_log)(t_all *all, t_philo *philo);
}				t_actions;

typedef struct s_all
{
	t_philo			*philos;
	t_mutex			*forks;
	t_thread		*threads;
	t_params		*param;
	t_actions		*act;
	t_mutex			*check_stop;
	int				stop;
}				t_all;

#endif