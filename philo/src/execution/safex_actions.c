/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safex_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:48:50 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/04 11:42:36 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"

int	safex(t_mutex *mutex, t_philo *philo, char *log, int function(t_philo *philo, char *log))
{
	int	function_return;
	char *message;
	
	if (!function || !mutex)
		return (FAIL);
	pthread_mutex_lock(mutex);
	message = log;
	function_return = function(philo, message);
	pthread_mutex_unlock(mutex);
	return (function_return);
}

int	have_to_stop(t_philo *philo, char *log)
{
	if (!philo)
		return (0);
	(void)log;
	if (philo->all->stop == true)
		return (1);
	return (0);
}

int is_dead(t_philo *philo, char *log)
{
	if (!philo)
		return (FAIL);
	(void)log;
	if ((get_full_timeofday() - philo->last_meal) >= philo->all->param->death_time)
		return (1);
	return (0);
}

int	last_meal(t_philo *philo, char *log)
{
	if (!philo)
		return (0);
	(void)log;
	if (philo->last_meal)
	philo->meal_count++;
	philo->last_meal = get_full_timeofday();
	philo->time_to_awake = (philo->last_meal + philo->all->param->eat_time);
	return (philo->last_meal);
}

int print_log(t_philo *philo, char *string)
{
	unsigned long timestamp;

	if (!philo || !string)
		return (0);
	timestamp = get_full_timeofday() - philo->all->param->start_time;
	put_number(timestamp);
	write(1, " ", 1);
	put_number(philo->id);
	write(1, " ", 1);
	put_message(STDOUT_FILENO, string, true);
	return (timestamp);	
}
