/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:13:50 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 23:09:52 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "utils.h"

//-core_execution.c ------------------------------------------------------------
int		init_mutexes(t_mutex *forks, t_mutex *stop, t_philo *philos, int size);
int		destroy_mutexes(t_mutex *forks, long size, t_mutex *stop, t_philo *philo);
void	*sentinel_routine(void *arg);
void	*routine(void *arg);
int 	threads_execution(t_all *all);

//-execution_utils.c ------------------------------------------------------------------
int		safex(t_mutex *mutex, t_philo *philo, t_log *log, int function(t_all *all, t_philo *philo));
void	*sentinel_routine(void *arg);
UL		get_full_timeofday(); // Get sec + micro_sec, transformed into mili_sec
int		sleep_until(UL time, t_all *all, t_philo *philo);//Short sleeps
int		eat_enough(t_all *all, t_philo *philo);

//-philo_actions.c -------------------------------------------------------------
int		philo_take_forks(t_mutex *forks, t_philo *philo, t_all *all);
int 	philo_eat(t_mutex *forks, t_philo *philo, t_all *all);
int		philo_leave_forks(t_philo *philo, t_all *all);
int		philo_sleep(UL sleep_time, t_philo *philo, t_all *all);
int     philo_think(t_philo *philo);

//-safex_actions.c --------------------------------------------------------------
int		have_to_stop(t_all *all, t_philo *philo);
int     stop(t_all *all, t_philo *philo);
int     is_dead(t_all *all, t_philo *philo);
int     last_meal(t_all *all, t_philo *philo);
int     print_log(t_all *all, t_philo *philo);

#endif
