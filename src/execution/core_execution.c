/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 15:05:38 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"

int init_mutexes(t_mutex *forks, t_mutex *stop, t_philo *philos, int size)
{
    int index;
	int	problem;
    
    if (!forks || size <= 0)
		return (0);
	problem = 0;
	problem += pthread_mutex_init(stop, NULL);
	if (!problem)
		problem += pthread_mutex_init(philos[index].check_message, NULL);
    index = 0;
    while (!problem && index < size)
    {
        problem += pthread_mutex_init(&(forks[index]), NULL);
		problem += pthread_mutex_init(philos[index].check_meal, NULL);
        index++;
    }
	if (problem)
		end_structures("Problem initiating mutex", 1);
    return (1);
}

int	destroy_mutexes(t_mutex *forks, long size, t_mutex *stop, t_philo *philos)
{
	int index;

	if (!forks || size <= 0 || !stop)
		return (0);
	pthread_mutex_destroy(stop);
	pthread_mutex_destroy(philos[index].check_message);
	index = 0;
	while (index < size)
	{
		pthread_mutex_destroy(philos[index].check_meal);
		pthread_mutex_destroy(&(forks[index]));
		index++;
	}
	return (1);
}

void    *routine(void *arg)
{
	t_all *all;
    t_philo *phi;
	t_params *param;

    if (!arg)
		return (NULL);
	phi = (t_philo *)arg;
	all = phi->all;
	param = all->param;
	while (safe(all->check_stop, all, NULL, have_to_stop) == false)
	{
		philo_take_forks(all->forks, phi);
		philo_eat(all->forks, phi);
		philo_leave_forks(all->forks, phi->right_hand, phi->left_hand);
		philo_sleep(param->sleep_time);
		philo_think(param.t)
		safe(phi->check_message, phi, &(t_log){IS_THINKING}, print_log);
	}
    return (NULL);
}

int threads_execution(t_all *all)
{
    int count;
	int	problem;
	int	index;
    
    if (!all || !all || !all->param || !all->threads || !all->philos)
        return (0);
	problem += pthread_create(&all->threads[count++], NULL, routine, all);
    count = -1;
    while (!problem && ++count < (all->param->philo_count))
		problem += pthread_create(&all->threads[count], NULL, routine, &(all->philos[count]));
	if (problem)
		safe(all->check_stop, NULL, all, stop_threads(all, NULL));
	index = -1;
	while (++index < count)
		pthread_join(all->threads[index], NULL);
    return (count);
}
