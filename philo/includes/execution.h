/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:13:50 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/04 12:02:51 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EXECUTION_H
# define EXECUTION_H

# include "utils.h"

//-core_execution.c ------------------------------------------------------------
void	*routine(void *arg);
void	*sentinel_routine(void *arg);

//-resource_management.c -----------------------------------------------------------
int		init_mutexes(t_mutex *forks, t_all *all, t_philo *philos, int size);
int		destroy_mutexes(t_mutex *forks, long size, t_all *all, t_philo *philo);
int 	init_threads(t_params *param, t_philo *philos, t_thread *threads, UL *count);
int     destroy_threads(t_thread *threads, UL *count, int philo_count);

//-philo_actions.c -------------------------------------------------------------
int		philo_take_forks(t_mutex *forks, t_philo *philo, t_all *all);
int 	philo_eat(t_mutex *forks, t_philo *philo, t_all *all);
int		philo_leave_forks(t_philo *philo, t_all *all);
int		philo_sleep(UL sleep_time, t_philo *philo, t_all *all);
int     philo_think(t_philo *philo, t_mutex *mutex);

//-safex_actions.c --------------------------------------------------------------
int		safex(t_mutex *mutex, t_philo *philo, char *log, int function(t_philo *philo, char *log));
int		have_to_stop(t_philo *philo, char *log);
int     is_dead(t_philo *philo, char *log);
int     last_meal(t_philo *philo, char *log);
int     print_log(t_philo *philo, char *log);

//-safex_utils.c ---------------------------------------------------------------
int     eat_enough(t_philo *philo, char *log);
int     stop(t_philo *philo, char *log);
UL		get_full_timeofday(); // Get sec + micro_sec, transformed into mili_sec
int		sleep_until(UL time, t_all *all, t_philo *philo);//Short sleeps


#endif
