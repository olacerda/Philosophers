/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:19:01 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:39:27 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	convert_argv_to_long(t_params *param, char **argv, UL start_time)
{
	if (!param || !argv)
		return (put_message(STDERR_FILENO,
			"NULL pointer in fill_Structures\n", true), 0);
	param->philo_count = ascii_to_long(argv[PHILO_COUNT]);
	if (!param->philo_count)
		return (0);
	param->death_time = ascii_to_long(argv[DEATH_TIME]);
	if (!param->death_time)
		return (0);
	param->eat_count = ascii_to_long(argv[EAT_COUNT]);
	if (!param->eat_count)
		return (0);
	param->eat_time = ascii_to_long(argv[EAT_TIME]);
	if (!param->eat_time)
		return (0);
	param->sleep_time = ascii_to_long(argv[SLEEP_TIME]);
	if (!param->sleep_time)
		return (0);
	param->start_time = start_time;
	return (1);
}

int create_arrays(t_all *all, int philo_nb)
{
    if (!all)
        return (0);
    all->forks = malloc(philo_nb * sizeof(t_mutex));
    if (!all->forks || !memory_zero(all->forks, (philo_nb * sizeof(t_mutex))))
        return (0);
    all->philos = malloc(philo_nb * sizeof(t_philo));
    if (!all->philos || !memory_zero(all->philos, philo_nb * sizeof(t_philo)))
        return (0);
    all->threads = malloc(philo_nb * sizeof(t_thread));
    if (!all->threads || !memory_zero(all->threads, philo_nb * sizeof(t_thread)))
        return (0);
    return (1);
}

int	initiate_philos(t_philo *philos, t_params *param, t_mutex *check_stop, int *stop)
{
	int	index;
	
	if (!philos || !param)
		return (0);
	index = -1;
	while (++index < param->philo_count)
	{
		philos[index].check_stop = check_stop;
		philos[index].stop = stop;
		philos[index].id = (index + 1);
		philos[index].eat_time = param->eat_time;
		philos[index].sleep_time = param->sleep_time;
		philos[index].start_time = param->start_time;
		philos[index].left_hand = (index + 1) % param->philo_count;
		philos[index].right_hand = index;							
		if (index == (param->philo_count - 1))
		{
			philos[index].left_hand = index;			
			philos[index].right_hand = (index + 1) % param->philo_count;			
		}
	}
	return (1);
}

int	fill_structs(t_all *all, char **argv)
{
	UL start_time;

	if (!all || !all->param || !argv)
		return (put_message(STDERR_FILENO,
			"NULL pointer in fill_Structures\n", true), 0);
	start_time = get_full_timeofday();
	if (!convert_argv_to_long(all->param, argv, start_time))
			return (end_structures("Failed convert_argv.. fill_structs", 1), 0);
	if (!create_arrays(all, all->param->philo_count))
			return (end_structures("Failed create_arrays fill_Struct", 1), 0);
	all->stop = false;
	pthread_mutex_init(all->stop, NULL);
	if (!initiate_philos(all->philos, all->param, start_time, &(all->stop)))
			return (end_structures("Failed initiate_philos fill_Struct", 1), 0);
	return (1);
}

