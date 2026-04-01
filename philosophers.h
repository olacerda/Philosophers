/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:24 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:39:56 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef enum	s_states
{
	TAKEN_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	DIED
}				t_states;

typedef enum s_args
{
	PHILO_COUNT = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	EAT_COUNT = 5,
}			t_args;

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
	t_mutex		*forks;
	long		eat_time;
	long		sleep_time;
	long		last_meal;
	int			right_hand;
	int			left_hand;
	UL			start_time;
	t_mutex		*check_stop;
	int			*stop;
}				t_philo;

typedef struct s_all
{
	t_philo			*philos;
	t_mutex			*forks;
	t_thread		*threads;
	t_params		*param;
	t_mutex			*check_stop;
	int				stop;
}				t_all;

#endif