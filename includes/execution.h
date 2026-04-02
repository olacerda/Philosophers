/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:13:50 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 15:01:56 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EXECUTION_H
# define EXECUTION_H

# include "utils.h"

//-core_execution.c ------------------------------------------------------------
int		init_mutexes(t_mutex *forks, t_mutex *stop, t_philo *philos, int size);
int 	threads_execution(t_all *all);
int		destroy_mutexes(t_mutex *forks, long size, t_mutex *stop, t_philo *philo);
void	*routine(void *arg);

//-philo_actions.c -------------------------------------------------------------
int		philo_take_forks(t_mutex *forks, t_philo *philo);
int 	philo_eat(t_mutex *forks, t_philo *philos);
int		philo_leave_forks(t_mutex *forks, int right_hand, int left_hand);
int 	philo_sleep(UL time_to_awake);
int     philo_think(UL time_to_awake);

//-safe_actions.c --------------------------------------------------------------
int     safe(t_mutex *mutex, t_philo *philo, void *arg, int function(t_all *all, t_philo *philo));
int     stop(t_all *all, t_philo *philo);
int     is_dead(t_all *all, t_philo *philo);
int		have_to_stop(t_all *all, t_philo *philo);
int     last_meal(t_all *all, t_philo *philo);
int     print_log(t_all *all, t_philo *philo);

#endif
