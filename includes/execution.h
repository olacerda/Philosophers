/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:13:50 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:23:32 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "utils.h"

//-core_execution.c ------------------------------------------------------------
int 	start_all_routines(t_all *all);
void	*routine(void *arg);
int		init_forks(t_mutex *forks, int size);
int		destroy_all_mutexes(t_mutex *forks, long size, t_mutex *stop);

//-philo_actions.c -------------------------------------------------------------
int		philo_take_forks(t_mutex *forks, t_philo *philo);
int 	philo_eat(t_mutex *forks, t_philo *philos);
int		philo_leave_forks(t_mutex *forks, int right_hand, int left_hand);
int 	philo_sleep(unsigned long time_to_awake);
int		philo_have_to_stop(t_mutex *check_stop, int stop);
// int		philo_think(t_mutex *forks, t_philo *philo, UL time_to_awake);

#endif
