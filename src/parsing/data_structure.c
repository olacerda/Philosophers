/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:19:01 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 15:00:13 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "parsing.h"
#include "execution.h"

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
    all->threads = malloc(philo_nb + 1 * sizeof(t_thread));
    if (!all->threads || !memory_zero(all->threads, philo_nb * sizeof(t_thread)))
        return (0);
    return (1);
}

int	initiate_philos(t_philo *philos, t_params *param, t_mutex *forks, t_all *all)
{
	int	index;
	UL	last_meal;
	
	if (!philos || !param)
		return (0);
	last_meal = get_full_timeofday();
	index = -1;
	while (++index < (param->philo_count - 1))
	{
		philos[index].id = (index + 1);
		philos[index].last_meal = last_meal;
		philos[index].right_hand = &(forks[index]);
		philos[index].left_hand = &(forks[(index + 1) % param->philo_count]);
		philos[index].all = all;
	}
	philos[index].id = (index + 1);
	philos[index].last_meal = last_meal;
	philos[index].left_hand = &(forks[index]);
	philos[index].right_hand = &(forks[(index + 1) % param->philo_count]);
	philos[index].all = all;
	return (1);
}

int	create_action_list(t_actions *act)
{
	if (!act)
		return (0);
	act->safe = safe;
	act->have_to_stop = have_to_stop;
	act->is_dead = is_dead;
	act->stop = stop;
	act->print_log = print_log;
}

int	fill_structs(t_all *all, char **argv)
{
	UL start_time;

	if (!all || !all->param || !argv)
		return (put_message(STDERR_FILENO,
			"NULL pointer in fill_Structures\n", true), 0);
	start_time = get_full_timeofday();
	all->stop = false;
	if (!convert_argv_to_long(all->param, argv, start_time))
			return (end_structures("Failed convert_argv.. fill_structs", 1), 0);
	if (!create_arrays(all, all->param->philo_count))
			return (end_structures("Failed create_arrays fill_Struct", 1), 0);
	if (!initiate_philos(all->philos, all->param, all->forks, all))
			return (end_structures("Failed initiate_philos fill_Struct", 1), 0);
	return (1);
}
