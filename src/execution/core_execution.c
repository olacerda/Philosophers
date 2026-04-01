/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:23:54 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int init_forks(t_mutex *forks, int size)
{
    int index;
    
    if (!forks || size <= 0)
        return (0);
    index = 0;
    while (index < size)
    {
        pthread_mutex_init(&(forks[index]), NULL);
        index++;
    }
    return (1);
}

int	destroy_all_mutexes(t_mutex *forks, long size, t_mutex *stop)
{
	int index;

	if (!forks || size <= 0 || !stop)
		return (0);
	pthread_mutex_destroy(stop);
	index = 0;
	while (index < size)
	{
		pthread_mutex_destroy(&(forks[index]));
		// pthread_mutex_destroy(&(philos[index].check_alive));
		index++;
	}
	return (1);
}

int start_all_routines(t_all *all)
{
    int index;
    
    if (!all || !all || !all->param || !all->threads || !all->philos)
        return (0);
    index = 0;
    while (index < all->param->philo_count)
    {
        pthread_create(&all->threads[index], NULL, routine, &(all->philos[index]));
        index++;
    }
	index = 0;
	while (index < all->param->philo_count)
	{
		pthread_join(all->threads[index], NULL);
		index++;
	}
	destroy_all_mutexes(all->forks, all->param->philo_count, all->stop);
    return (1);
}

void    *routine(void *arg)
{
    t_philo *phi;

    if (!arg)
		return (NULL);
	phi = (t_philo *)arg;
	while (1)
	{
		if (philo_have_to_stop(phi->check_stop, phi->stop) == true)
			break ;
		philo_take_forks(phi->forks, phi);
		philo_eat(phi->forks, phi);
		philo_leave_forks(phi->forks, phi->right_hand, phi->left_hand);
		philo_sleep(get_full_timeofday() + phi->sleep_time);
		// philo_think(phi->forks, phi, get_full_timeofday() + phi.)
		print_log(phi->id, IS_THINKING, phi->start_time);		
	}
    return (NULL);
}
