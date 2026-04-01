/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:17:56 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 02:33:46 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int sleep_until(unsigned long time)
{
	if (time <= 0)
		return (0);
	while (get_full_timeofday() < time)
		usleep(500);
	return (1);
}