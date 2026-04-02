/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:30:40 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/03 00:33:50 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	*sentinel_routine(void *arg)
{
	t_all	*all;
	t_philo *philos;
	UL		index;
	int		eaten_enough;

	if (!arg)
		return (NULL);
	all = (t_all *)arg;
	philos = all->philos;
	while (!all->stop)
	{
		index = 0;
		eaten_enough = 1;
		while (index < all->param->philo_count)
		{
			if (safex(&(philos[index].check_meal), &(philos[index]), NULL, is_dead))
				safex(&(all->check_stop), NULL, NULL, stop);			
			index++;
			if (all->param->eat_count >= 0)
				eaten_enough &= safex(&(philos[index].check_meal), philos, NULL, eat_enough);
		}
		if ((all->param->eat_count >= 0) && eaten_enough == true)
			safex(&(all->check_stop), NULL, NULL, stop);
	}
	return (NULL);
}

int	eat_enough(t_all *all, t_philo *philo)
{
	if (!philo || !all)
		return (0);
	if (philo->meal_count >= all->param->eat_count)
		return (1);
	return (0);
}

void    *routine(void *arg)
{
	t_all *all;
    t_philo *phi;
	t_params *param;

    if (!arg)
		return (NULL);
	phi = (t_philo *)arg;
	all = phi->all;
	param = all->param;
	while (safex(&(all->check_stop), phi, NULL, have_to_stop) == false)
	{
		philo_take_forks(all->forks, phi, all);
		dprintf(2, "taken forks\n");
		philo_eat(all->forks, phi, all);
		dprintf(2, "eaten\n");
		philo_leave_forks(phi, all);
		dprintf(2, "leaved forks\n");
		philo_sleep(param->sleep_time, phi, all);
		dprintf(2, "sleeped\n");
		philo_think(phi);
		safex(&(phi->check_message), phi, &(t_log){IS_THINKING}, print_log);
	}
    return (NULL);
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
