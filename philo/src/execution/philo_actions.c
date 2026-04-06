/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 01:57:56 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/06 12:12:50 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"

int philo_sleep(UL sleep_time, t_philo *philo, t_all *all)
{
	if (sleep_time <= 0 || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	philo->time_to_awake = get_full_timeofday() + sleep_time;
	safex(&(all->check_stop), philo, "is sleeping", print_log);
	sleep_until(philo->time_to_awake, all, philo);
    return (1);
}

int	philo_leave_forks(t_philo *philo, t_all *all)
{
	if (!philo || !all)
		return (0);
	pthread_mutex_unlock(philo->left_hand);
	pthread_mutex_unlock(philo->right_hand);
	if (safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	return (1);
}

int	philo_take_forks(t_mutex *forks, t_philo *philo, t_all *all)
{
	if (!forks || !philo || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	pthread_mutex_lock(philo->right_hand);
	if (safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (pthread_mutex_unlock(philo->right_hand), 0);
	safex(&(all->check_stop), philo, "has taken a fork", print_log);
	pthread_mutex_lock(philo->left_hand);
	if (safex(&(all->check_stop), philo, NULL, have_to_stop))
	{
		pthread_mutex_unlock(philo->left_hand);
		if (philo->right_hand != philo->left_hand)
			pthread_mutex_unlock(philo->right_hand);
		return (0);
	}
	safex(&(all->check_stop), philo, "has taken a fork", print_log);
	return (1);
}

int philo_eat(t_mutex *forks, t_philo *philo, t_all *all)
{
    if (!forks || !philo || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (-1);
	safex(&(philo->check_meal), philo, NULL, last_meal);
	safex(&(all->check_stop), philo, "is eating", print_log);
	sleep_until(philo->time_to_awake, all, philo);
    return (1);
}

int	philo_think(t_philo *philo, t_mutex *mutex)
{
	unsigned long sleep_time;
	unsigned long limit;

	if (!philo || safex(mutex, philo, NULL, have_to_stop))
		return (0);
	safex(mutex, philo, "is thinking", print_log);
	if (philo->id % 2 == 0)
		usleep(10);
	limit = philo->all->param->death_time - (philo->all->param->eat_time + philo->all->param->sleep_time);
	if ((philo->id % 2) == 0)
		sleep_time = (philo->all->param->eat_time / 2) % limit;
	else
		sleep_time = 5;
	sleep_time += get_full_timeofday();
	sleep_until(sleep_time, philo->all, philo);
	return (1);
}

