/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/03 00:59:49 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "execution.h"
#include "parsing.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_all *all;

	(void)argc;
	(void)argv;
	all = init_structs();
	if (!parse(argc, argv))
		return (end_structures("Error parse"), 1);
	// dprintf(2, "eat_count main: %li\n", all->param->eat_count);
	if (!fill_structs(all, argc, argv))
		return (end_structures("Error fill_structures"), 1);
	UL	index = 0;
	dprintf(2, "death_time == %lu\n", all->param->death_time);
	dprintf(2, "eat_time == %lu\n", all->param->eat_time);
	dprintf(2, "eat_count == %li\n", all->param->eat_count);
	dprintf(2, "sleep_time == %lu\n", all->param->sleep_time);
	dprintf(2, "philo_count == %lu\n", all->param->philo_count);
	dprintf(2, "start_time == %lu\n", all->param->start_time);
	while (index < all->param->philo_count)
	{
		if (pthread_mutex_init(&all->forks[index], NULL) != 0)
			dprintf(2, "forks[%lu] == NULL\n", index);
		index++;
	}
	exit(1);
		
	init_mutexes(all->forks, &(all->check_stop), all->philos, all->param->philo_count);
	threads_execution(all);
	destroy_mutexes(all->forks, all->param->philo_count, &(all->check_stop), all->philos);
	return (end_structures(NULL), 0);
}
