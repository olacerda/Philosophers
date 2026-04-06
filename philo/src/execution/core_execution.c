/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/06 14:13:32 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"

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
		if (!philo_take_forks(all->forks, phi, all)
			|| !philo_eat(all->forks, phi, all)
			|| !philo_leave_forks(phi, all)
			|| !philo_sleep(param->sleep_time, phi, all)
			|| !philo_think(phi, &(all->check_stop)))
			break ;
	}
	// dprintf(2, "exiting philo %d\n", phi->id);
	    return (NULL);
}

void	*sentinel_routine(void *arg)
{
	t_all	*all;
	t_philo *philos;
	UL		index;
	int		eaten_enough;
	int	go;

	if (!arg)
		return (NULL);
	all = (t_all *)arg;
	philos = all->philos;
	go = 1;
	while (go)
	{
		index = -1;
		eaten_enough = 1;
		while (go && ++index < all->param->philo_count)
		{
			if (safex(&(philos[index].check_meal), &(philos[index]), NULL, is_dead))
			{
				safex(&(all->check_stop), &(philos[index]), "died", print_log);
				safex(&(all->check_stop), &(philos[index]), NULL, stop);
				if (philos[index].right_hand == philos[index].left_hand)
					pthread_mutex_unlock(philos[index].right_hand);
				go = false;
			}
			if (go && all->param->eat_count >= 0)
			{
				if (!safex(&(philos[index].check_meal), &(philos[index]), NULL, eat_enough))
					eaten_enough = false;
			}
		}
		if (go && (all->param->eat_count >= 0) && eaten_enough == true)
		{
			safex(&(all->check_stop), philos, NULL, stop);
			go = false;
		}
		usleep(500);
	}
	return (NULL);
}
