/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safex_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:48:50 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/03 00:13:24 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (get_full_timeofday() - philo->last_meal >= all->param->death_time)
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
	if (philo->last_meal)
	philo->meal_count++;
	philo->last_meal = safex(&(philo->check_message), philo, &(t_log){IS_EATING}, print_log);
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

	if (!philo || !all || !philo->message)
		return (0);
	timestamp = get_full_timeofday() - all->param->start_time;
	put_number(timestamp);
	write(1, " ", 1);
	put_number(philo->id);
	write(1, " ", 1);
	put_message(STDOUT_FILENO, (char *)(logs[*(philo->message)]), true);
	return (timestamp);	
}
