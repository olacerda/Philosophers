/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safex_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:48:50 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/05 03:43:13 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		//dprintf(2, "have to stop\n");
		return (1);
	}
	return (0);
}

int is_dead(t_philo *philo, char *log)
{
	if (!philo)
		return (FAIL);
	(void)log;
	if ((get_full_timeofday() - philo->last_meal) >= philo->all->param->death_time)
	{
		// safex(&(philo->all->check_message), philo, "died", print_log);
		return (1);
	}
	return (0);
}

int	last_meal(t_philo *philo, char *log)
{
	if (!philo)
		return (0);
	(void)log;
	if (philo->last_meal)
	philo->meal_count++;
	//dprintf(2, "meal_count: %li\n", philo->meal_count);
	philo->last_meal = get_full_timeofday();
	philo->time_to_awake = (philo->last_meal + philo->all->param->eat_time);
	return (philo->last_meal);
}

int print_log(t_philo *philo, char *string)
{
	unsigned long timestamp;

	if (!philo || !string
		|| safex(&(philo->all->check_stop), philo, NULL, have_to_stop))
		return (0);
	timestamp = get_full_timeofday() - philo->all->param->start_time;
	put_number(timestamp);
	write(1, " ", 1);
	put_number(philo->id);
	write(1, " ", 1);
	put_message(STDOUT_FILENO, string, true);
	return (timestamp);	
}
