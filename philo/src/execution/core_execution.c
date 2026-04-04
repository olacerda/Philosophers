/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/04 12:27:07 by olacerda         ###   ########.fr       */
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
		philo_take_forks(all->forks, phi, all);
		philo_eat(all->forks, phi, all);
		philo_leave_forks(phi, all);
		philo_sleep(param->sleep_time, phi, all);
		philo_think(phi, &(all->check_message));
	}
    return (NULL);
}

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
	while (1)
	{
		index = -1;
		eaten_enough = 1;
		while (++index < all->param->philo_count)
		{
			if (safex(&(philos[index].check_meal), &(philos[index]), NULL, is_dead))
			{
				safex(&(all->check_stop), NULL, NULL, stop);			
				break ;
			}
			if (all->param->eat_count >= 0)
				eaten_enough &= safex(&(philos[index].check_meal), philos, NULL, eat_enough);
		}
		if ((all->param->eat_count >= 0) && eaten_enough == true)
		{
			safex(&(all->check_stop), NULL, NULL, stop);
			break ;
		}
	}
	return (NULL);
}
