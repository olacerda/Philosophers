/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/05 03:50:22 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		//dprintf(2, "##################### safex stop == %d #############\n",
			// (safex(&(all->check_stop), phi, NULL, have_to_stop) == false));
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
	//dprintf(2, "after comecou thread SENTINEL\n");
	all = (t_all *)arg;
	philos = all->philos;
	//dprintf(2, "%lu\n", all->param->eat_count);
	int	go;

	go = 1;
	while (go)
	{
		index = -1;
		eaten_enough = 1;
		while (go && ++index < all->param->philo_count)
		{
			if (safex(&(philos[index].check_meal), &(philos[index]), NULL, is_dead))
			{
				safex(&(all->check_message), &(philos[index]), "died", print_log);
				safex(&(all->check_stop), &(philos[index]), NULL, stop);
				go = false;
				break ;
			}
			if (all->param->eat_count >= 0)
			{
				eaten_enough &= safex(&(philos[index].check_meal), philos, NULL, eat_enough);
				//dprintf(2, "eaten_enough: %d\n", eaten_enough);
			}
		}
		// if ((all->param->eat_count >= 0) && eaten_enough == true)
		// {
		// 	//dprintf(2, "############### eaten_enough == true##################3\n");
		// 	safex(&(all->check_stop), &(philos[index]), NULL, stop);
		// 	break ;
		// }
		usleep(500);
	}
	return (NULL);
}
