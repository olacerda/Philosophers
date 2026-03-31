/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:19:01 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/31 11:40:33 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"
#include "parsing.h"
#include "utils.h"

int	convert_argv_to_long(t_params *param, char **argv)
{
	if (!argv)
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
	return (1);
}

int create_arrays(t_info *inf, int philo_nb)
{
    if (!inf)
        return (0);
    inf->fork = malloc(philo_nb * sizeof(pthread_mutex_t));
    if (!inf->fork || !memory_zero(inf->fork, (philo_nb * sizeof(int))))
        return (0);
    inf->philo = malloc(philo_nb * sizeof(int));
    if (!inf->philo || !memory_zero(inf->philo, philo_nb * sizeof(int)))
        return (0);
    inf->thread = malloc(philo_nb * sizeof(pthread_t));
    if (!inf->thread || !memory_zero(inf->thread, philo_nb * sizeof(pthread_t)))
        return (0);
    return (1);
}

int	initiate_philos(t_philo *philo, int	philo_count)
{
	int	index;
	
	if (!philo || philo_count <= 0)
		return (0);
	index = 0;
	while (index < philo_count)
	{
		philo[index].alive = true;
		philo[index].right_hand = (index + 1) % philo_count;
		philo[index].left_hand = index;
		index++;
	}
	return (1);
}

int	fill_structs(t_all *all, char **argv)
{
	if (!all || !all->param || !all->info || !argv)
		return (put_message(STDERR_FILENO,
			"NULL pointer in fill_Structures\n", true), 0);
	if (!convert_argv_to_long(all->param, argv))
			return (end_structures("Failed convert_argv.. fill_structs", 1), 0);
	if (!create_arrays(all->info, all->param->philo_count))
			return (end_structures("Failed create_arrays fill_Struct", 1), 0);
	if (!initiate_philos(all->info->philo, all->param->philo_count))
			return (end_structures("Failed initiate_philos fill_Struct", 1), 0);
	all->initial_time = get_full_timeofday();
	return (1);
}

