/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:24 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 07:22:44 by otlacerd         ###   ########.fr       */
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

// # define PHILO_COUNT 1
// # define DIE_TIME 2
// # define EAT_TIME 3
// # define SLEEP_TIME 4
// # define EAT_COUNT 5
# define FAIL -1

typedef enum s_args
{
	PHILO_COUNT = 1,
	DEATH_TIME = 2,
	EAT_TIME = 3,
	SLEEP_TIME = 4,
	EAT_COUNT = 5,
}			t_args;

typedef struct s_phi
{
	long	philo_count;
	long	eat_count;
	long	death_time;
	long	eat_time;
	long	sleep_time;
}			t_phi;

#endif