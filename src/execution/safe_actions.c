/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:48:50 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/02 14:10:34 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"

int	have_to_stop(t_all *all, t_philo *philo)
{
	if (!all)
		return (0);
	(void)philo;
	if (all->stop == true)
		return (1);
	return (0);
}

int is_dead(t_all *all, t_philo *philo)
{
	if (!all || !philo)
		return (FAIL);
	if (get_full_timeofday() - *philo->last_meal >= all->param->death_time)
		return (1);
	return (0);
}

int	stop(t_all *all, t_philo *philo)
{
	if (!all)
		return (0);
	(void)philo;
	all->stop = true;
	return (1);	
}

int	last_meal(t_all *all, t_philo *philo)
{
	if (!philo)
		return (0);
	(void)all;
	philo->last_meal = safe(philo->check_message, philo, &(t_log){IS_EATING}, print_log);
	philo->time_to_awake = (philo->last_meal + all->param->eat_time);
	return (1);
}

int print_log(t_all *all, t_philo *philo)
{
	unsigned long timestamp;
	const char *logs[] = {
		"has taken a fork",
			"is eating",
				"is sleeping",
					"is thinking",
						"died", NULL};

	if (!philo || !all)
		return (0);
	timestamp = get_full_timeofday() - all->param->start_time;
	put_number(timestamp);
	write(1, " ", 1);
	put_number(philo->id);
	write(1, " ", 1);
	put_message(STDOUT_FILENO, (char *)(logs[philo->message]), true);
	return (timestamp);	
}

void	*sentinel_routine(void *arg)
{
	t_all	*all;
	t_philo *philos;
	int		index;
	unsigned long	current_time;

	if (!arg)
		return (NULL);
	all = (t_all *)arg;
	philos = all->philos;
	while (!all->stop)
	{
		current_time = get_full_timeofday();
		index = -1;
		while (++index < all->param->philo_count)
		{
			if (safe(philos[index].last_meal, &(philos[index]), all, is_dead))
				safe(all->check_stop, &(philos[index]), all, stop);
		}
	}
	return (NULL);
}

int	safe(t_mutex *mutex, t_philo *philo, void *arg, int function(t_all *all, t_philo *philo))
{
	int	function_return;
	
	if (!function || !mutex)
		return (FAIL);
	pthread_mutex_lock(mutex);
	function_return = function(philo->all, philo);
	pthread_mutex_unlock(mutex);
	return (function_return);
}