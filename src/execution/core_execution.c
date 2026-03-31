/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:25:34 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/31 11:24:09 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "execution.h"
#include "parsing.h"
#include "utils.h"

unsigned long   get_full_timeofday()
{
    unsigned long full;
    t_time time;

    if (gettimeofday(&time, NULL) == -1)
    {
        put_message(STDERR_FILENO, "gettimeofday: ", false);
        end_structures(translate_errno(errno), 1);
        return (0);
    }
    full = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (full);
}

int start_all_routine(t_info *info, t_params *param)
{
    int index;
    
    if (!info)
        return (0);
    index = 0;
    while (index < param->philo_count)
    {
        pthread_create(info->thread[index], NULL, routine, param);
        index++;
    }
    return (1);
}

int philo_eat()
{
    
}

int philo_think(pthread_mutex_t *forks, t_philo *philo)
{
    unsigned long before;
    unsigned long after;

    if (!forks || !philo)
        return (-1);
    before = get_full_timeofday();
    pthread_mutex_lock(&(forks[philo->right_hand]));
    pthread_mutex_lock(&(forks[philo->left_hand]));
    after = get_full_timeofday();
    return (after - before);
}

int philo_sleep(unsigned long time_to_awake)
{
    if (time_to_awake <= 0)
        return (0);
    while (get_full_timeofday() < time_to_awake)
        usleep(500);
    return (1);
}


void    *routine(void *arg)
{
    t_all *all;

    if (!arg)
        return (NULL);
    all = (t_all *)arg;
    philo_think(all->info, all->philo);
    philo_sleep(get_full_timeofday() + param->sleep_time);
    return (NULL);
}
