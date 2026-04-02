/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 01:57:56 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 15:16:20 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"

int philo_sleep(UL sleep_time, t_philo *philo)
{
	if (sleep_time <= 0)
		return (0);
	philo->time_to_awake = get_full_timeofday() + sleep_time;
	safe(philo->check_message, philo, NULL, print_log);
	sleep_until(philo->time_to_awake);
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
	pthread_mutex_lock(&(philo->right_hand));
	safe(philo, philo->check_message, &(t_log){TAKEN_FORK}, print_log);
	pthread_mutex_lock(&(philo->left_hand));
	safe(philo, philo->check_message, &(t_log){TAKEN_FORK}, print_log);
	return (1);
}

int philo_eat(t_mutex *forks, t_philo *philo)
{
    if (!forks || !philo)
        return (0);
	safe(philo->check_meal, philo->all, NULL, last_meal);
	safe(philo, philo->check_message, &(t_log){IS_EATING}, print_log);
	sleep_until(philo->time_to_awake);
    return (1);
}

int	philo_think(UL sleep_time)
{
	if (sleep_time < 0)
		return (0);
	sleep_until(get_full_timeofday() + sleep_time);
	return (1);
}

