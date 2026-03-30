/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:24 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/30 15:56:11 by olacerda         ###   ########.fr       */
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

typedef enum s_args
{
	PHILO_COUNT = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	EAT_COUNT = 5,
}			t_args;

typedef struct timeval t_time;

typedef struct s_params
{
	long			philo_count;
	long			death_time;
	long			eat_time;
	long			sleep_time;
	long			eat_count;
}			t_params;

typedef struct s_philo
{
	int				alive;
	int				eating;
	int				sleeping;
	int				thinking;
	int				forks_holding;
}			t_philo;

typedef struct s_info
{
	t_philo			*philo; // [0] == philos_size philo, [1] == first philo, etc etc
	int				*fork;
	unsigned long 	initial_time;
	pthread_t	*thread;
}			t_info;

typedef struct s_all
{
	t_params		*param;
	t_info			*info;
	unsigned long	initial_time;
}			t_all;

#endif