/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:24:18 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/05 02:38:33 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	stop(t_philo *philo, char *log)
{
	if (!philo)
		return (0);
	(void)log;
	philo->all->stop = true;
	return (1);	
}

int	eat_enough(t_philo *philo, char *log)
{
	if (!philo)
		return (0);
	(void)log;
	if (philo->meal_count >= philo->all->param->eat_count)
	{
		// //dprintf(2, "---> eat_enough:\n meal_count: %lu    eat_count: %li\n", philo->meal_count, philo->all->param->eat_count);
		return (1);
	}
	return (0);
}

unsigned long   get_full_timeofday()
{
    unsigned long full;
    t_time time;

    if (gettimeofday(&time, NULL) == -1)
    {
        put_message(STDERR_FILENO, "gettimeofday: ", false);
        end_structures(translate_errno(errno));
        return (0);
    }
    full = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (full);
}

int sleep_until(UL time, t_all *all, t_philo *philo)
{
	if (time <= 0 || safex(&(all->check_stop), philo, NULL, have_to_stop))
		return (0);
	while (get_full_timeofday() < time)
	{
		usleep(500);
		if (safex(&(all->check_stop), philo, NULL, have_to_stop))
			break ;
	}
	return (1);
}
