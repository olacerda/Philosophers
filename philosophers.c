/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 09:38:37 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"
#include "execution.h"
#include "parsing.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_all *all;

	(void)argc;
	(void)argv;
	UL curret_time = get_full_timeofday();
	all = init_structs();
	if (!parse(argc, argv))
		return (end_structures("Error parse", 1), 1);
	if (!fill_structs(all, argv))
		return (end_structures("Error fill_structures", 1), 1);
	
	init_mutexes(all->forks, all->check_stop, all->philos, all->param->philo_count);
	threads_execution(all);
	destroy_mutexes(all->forks, all->param->philo_count, all->check_stop, all->philos);
	
	int index = 0;
	while (index < all->param->philo_count)
	{
		dprintf(2, "philo id: %d\n", all->philos[index].id);
		dprintf(2, "philos: %d right: %d left: %d\n\n", index, all->philos[index].right_hand, all->philos[index].left_hand);
		index++;
	}
	dprintf(2, "first line time: %li\n", curret_time);
	dprintf(2, "last line time: %li\n", get_full_timeofday() - curret_time);
	return (end_structures(NULL, 0), 0);
}
