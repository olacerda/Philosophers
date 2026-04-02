/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/03 00:10:20 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	safex(t_mutex *mutex, t_philo *philo, t_log *log, int function(t_all *all, t_philo *philo))
{
	int	function_return;
	
	if (!function || !mutex)
		return (FAIL);
	pthread_mutex_lock(mutex);
	if (log != NULL)
		philo->message = log;
	function_return = function(philo->all, philo);
	philo->message = NULL;
	pthread_mutex_unlock(mutex);
	return (function_return);
}

int init_mutexes(t_mutex *forks, t_mutex *stop, t_philo *philos, int size)
{
    int index;
	int	problem;
    
    if (!forks || size <= 0 || !philos)
		return (0);
	dprintf(2, "mutex0\n");
    index = 0;
	problem = 0;
	dprintf(2, "e aqui?\n");
	if (stop == NULL)
		dprintf(2, "stop e null\n");
	problem += pthread_mutex_init(stop, NULL);
	dprintf(2, "mutex1\n");
	if (!problem)
		problem += pthread_mutex_init(&(philos[index].check_message), NULL);
	dprintf(2, "mutex2\n");
    while (!problem && index < size)
    {
		dprintf(2, "mutex3\n");
        problem += pthread_mutex_init(&(forks[index]), NULL);
		problem += pthread_mutex_init(&(philos[index].check_meal), NULL);
        index++;
    }
	if (problem)
		end_structures("Problem initiating mutex");
    return (1);
}

int	destroy_mutexes(t_mutex *forks, long size, t_mutex *stop, t_philo *philos)
{
	int index;

	if (!forks || size <= 0 || !stop)
		return (0);
	index = 0;
	pthread_mutex_destroy(stop);
	pthread_mutex_destroy(&(philos[index].check_message));
	while (index < size)
	{
		pthread_mutex_destroy(&(philos[index].check_meal));
		pthread_mutex_destroy(&(forks[index]));
		index++;
	}
	return (1);
}

int threads_execution(t_all *all)
{
    UL	count;
	int	problem;
	UL	index;
    
    if (!all || !all->param || !all->threads || !all->philos)
		return (0);
	problem = 0;
	problem += pthread_create(&all->threads[all->param->philo_count], NULL, routine, all);
    count = 0;
    while (!problem && (count < all->param->philo_count))
	{
		problem += pthread_create(&all->threads[count], NULL, routine, &(all->philos[count]));
		count++;
	}
	if (problem)
		safex(&(all->check_stop), all->philos, NULL, stop);
	index = 0;
	while (index < count)
	{
		pthread_join(all->threads[index], NULL);
		index++;
	}
	pthread_join(all->threads[all->param->philo_count], NULL);
    return (count);
}
