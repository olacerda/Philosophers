/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:13:50 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/31 10:09:29 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EXECUTION_H
# define EXECUTION_H

# include "philosophers.h"

//-core_execution.c ------------------------------------------------------------
unsigned long   get_full_timeofday();

//-init_data.c -----------------------------------------------------------------
int             init_all_forks(pthread_mutex_t *forks, int size);

#endif