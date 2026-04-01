/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 01:57:56 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:13:38 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int philo_sleep(unsigned long time_to_awake)
{
	if (time_to_awake <= 0)
		return (0);
	sleep_until(time_to_awake);
    return (1);
}

int	philo_leave_forks(t_mutex *forks, int right_hand, int left_hand)
{
	if (!forks)
		return (0);
	pthread_mutex_unlock(&(forks[right_hand]));
	pthread_mutex_unlock(&(forks[left_hand]));
	return (1);
}

int	philo_take_forks(t_mutex *forks, t_philo *philo)
{
	if (!forks || !philo)
		return (0);
	pthread_mutex_lock(&(forks[philo->right_hand]));
	print_log(philo->id, TAKEN_FORK, philo->start_time);
	pthread_mutex_lock(&(forks[philo->left_hand]));
	print_log(philo->id, TAKEN_FORK, philo->start_time);
	return (1);
}

int philo_eat(t_mutex *forks, t_philo *philo)
{
    unsigned long time_to_awake;

    if (!forks || !philo)
        return (0);
    pthread_mutex_lock(&(forks[philo->right_hand]));
	print_log(philo->id, TAKEN_FORK, philo->start_time);
    pthread_mutex_lock(&(forks[philo->left_hand]));
	print_log(philo->id, TAKEN_FORK, philo->start_time);
	print_log(philo->id, IS_EATING, philo->start_time);
	philo->last_meal = get_full_timeofday();
	time_to_awake = philo->last_meal + philo->eat_time;
	sleep_until(time_to_awake);
    return (1);
}

int	philo_have_to_stop(t_mutex *check_stop, int stop)
{
	if (!check_stop)
		return (0);
	pthread_mutex_lock(check_stop);
	if (stop == true)
		return (1);
	pthread_mutex_unlock(check_stop);	
	return (0);
}
