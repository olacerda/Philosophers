/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:30:40 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/04 21:18:28 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int init_threads(t_params *param, t_philo *philos, t_thread *threads, UL *count)
{
	int	problem;
    
    if (!param || !threads || !philos || !count)
		return (0);
	problem = 0;
	problem += pthread_create(&threads[param->philo_count], NULL, sentinel_routine, philos->all);
    while (!problem && ((*count) < param->philo_count))
	{
		problem += pthread_create(&threads[(*count)], NULL, routine, &(philos[(*count)]));
		(*count)++;
	}
	if (problem)
		safex(&(philos->all->check_stop), philos, NULL, stop);
    return ((*count));
}

int init_mutexes(t_mutex *forks, t_all *all, t_philo *philos, int size)
{
    int index;
	int	problem;
    
    if (!forks || size <= 0 || !philos || !all)
		return (0);
    index = 0;
	problem = 0;
	problem += pthread_mutex_init(&(all->check_stop), NULL);
	if (!problem)
		problem += pthread_mutex_init(&(all->check_message), NULL);
    while (!problem && index < size)
    {
        problem += pthread_mutex_init(&(forks[index]), NULL);
		problem += pthread_mutex_init(&(philos[index].check_meal), NULL);
        index++;
    }
	if (problem)
		end_structures("Problem initiating mutex");
    return (1);
}

int	wait_threads(t_thread *threads, UL *count, int philo_count)
{
	UL	index;

	if (!threads || philo_count <= 0)
		return (0);
	index = 0;
	while (index < (*count))
	{
		pthread_join(threads[index], NULL);
		index++;
	}
	pthread_join(threads[philo_count], NULL);
	return (1);
}

int	destroy_mutexes(t_mutex *forks, long size, t_all *all, t_philo *philos)
{
	int index;

	if (!forks || size <= 0 || all)
		return (0);
	index = 0;
	pthread_mutex_destroy(&(all->check_stop));
	pthread_mutex_destroy(&(all->check_message));
	while (index < size)
	{
		pthread_mutex_destroy(&(philos[index].check_meal));
		pthread_mutex_destroy(&(forks[index]));
		index++;
	}
	return (1);
}
