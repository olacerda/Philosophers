/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 01:57:56 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/03 00:18:36 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int philo_sleep(UL sleep_time, t_philo *philo, t_all *all)
{
	if (sleep_time <= 0 || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	philo->time_to_awake = get_full_timeofday() + sleep_time;
	safex(&(philo->check_message), philo, NULL, print_log);
	sleep_until(philo->time_to_awake, all, philo);
    return (1);
}

int	philo_leave_forks(t_philo *philo, t_all *all)
{
	if (!philo || !all || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	pthread_mutex_unlock(philo->right_hand);
	pthread_mutex_unlock(philo->left_hand);
	return (1);
}

int	philo_take_forks(t_mutex *forks, t_philo *philo, t_all *all)
{
	if (!forks || !philo || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	pthread_mutex_lock(philo->right_hand);
	safex(&(philo->check_message), philo, &(t_log){TAKEN_FORK}, print_log);
	if (safex(&(all->check_stop), philo, NULL, have_to_stop))
	{
		pthread_mutex_unlock(philo->right_hand);
		return (0);
	}
	pthread_mutex_lock(philo->left_hand);
	safex(&(philo->check_message), philo, &(t_log){TAKEN_FORK}, print_log);
	if (safex(&(all->check_stop), philo, NULL, have_to_stop))
	{
		pthread_mutex_unlock(philo->left_hand);
		pthread_mutex_unlock(philo->right_hand);
		return (0);
	}
	return (1);
}

int philo_eat(t_mutex *forks, t_philo *philo, t_all *all)
{
    if (!forks || !philo || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	dprintf(2, "before safex\n");
	safex(&(philo->check_meal), philo, NULL, last_meal);
	dprintf(2, "after safex\n");
	sleep_until(philo->time_to_awake, all, philo);
    return (1);
}

int	philo_think(t_philo *philo)
{
	if (!philo)
		return (0);
	safex(&(philo->check_message), philo, &(t_log){IS_THINKING}, print_log);
	return (1);
}

