/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/05 02:38:33 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "execution.h"
#include "parsing.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_all					*all;
	UL		count;

	all = init_structs();
	count = 0;
	if (!parse(argc, argv))
		return (end_structures("Error parse"), 1);
	if (!fill_structs(all, argc, argv))
		return (1);
	UL	line = 0;
	while (line < all->param->philo_count)
	{
		//dprintf(2, "philo[%lu] == %lu\n", line, all->philos[line].meal_count);
		line++;
	}
	init_mutexes(all->forks, all, all->philos, all->param->philo_count);
	init_threads(all->param, all->philos, all->threads, &count);
	wait_threads(all->threads, &count, all->param->philo_count);
	destroy_mutexes(all->forks, all->param->philo_count, all, all->philos);
	end_structures(NULL);
	return (0);
}
