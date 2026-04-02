/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:24 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/03 00:34:38 by otlacerd         ###   ########.fr       */
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
	UL		philo_count;
	UL		death_time;
	UL		eat_time;
	UL		sleep_time;
	long	eat_count;
	UL		start_time;
}			t_params;


typedef struct s_philo
{
	int				id;
	UL				last_meal;
	long			meal_count;
	t_mutex			check_meal;
	UL				time_to_awake;
	t_mutex			*right_hand;
	t_mutex			*left_hand;
	t_log			*message;
	t_mutex			check_message;
	struct s_all	*all;
}				t_philo;

typedef struct s_all
{
	int				argc;
	t_philo			*philos;
	t_mutex			*forks;
	t_thread		*threads;
	t_params		*param;
	t_mutex			check_stop;
	int				stop;
}				t_all;

#endif