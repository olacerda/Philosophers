/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:19:42 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "execution.h"
#include "parsing.h"
#include "utils.h"

void	*sentinel_routine(void *arg)
{
	t_all	*all;
	t_philo *philos;
	int		stop;
	int		index;

	if (!arg)
		return (NULL);
	all = (t_all *)arg;
	philos = all->philos;
	while (!stop)
	{
		index = 0;
		while (index < all->param->philo_count)
		{
			pthread_mutex_lock(&philos[index].check_alive);
			if (!philos[index].is_alive)
			{
				pthread_mutex_lock(&(all->stop))
				
			}
			index++;
		}
	}
}

int	init_sentinel(t_philo *philos)
{
	pthread_t sentinel;

	pthread_create(sentinel, NULL, sentinel_routine, philos);
}

int	main(int argc, char *argv[])
{
	t_all *all;

	(void)argc;
	(void)argv;
	all = init_structs();
	if (!parse(argc, argv))
		return (end_structures("Error parse", 1), 1);
	if (!fill_structs(all, argv))
		return (end_structures("Error fill_structures", 1), 1);
	int index = 0;
	while (index < all->param->philo_count)
	{
		dprintf(2, "philo id: %d\n", all->philos[index].id);
		dprintf(2, "philos: %d right: %d left: %d\n\n", index, all->philos[index].right_hand, all->philos[index].left_hand);
		index++;
	}
	dprintf(2, "start_time: %li\n", all->philos[0].start_time);
	return (end_structures(NULL, 0), 0);
}
