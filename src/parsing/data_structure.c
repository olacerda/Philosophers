/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:19:01 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 07:38:46 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

int	end_structures(t_phi *phi)
{
	if (!phi)
		return (put_message(STDERR_FILENO, "NULL pointer in end_Structures\n"),
			0);
	free(phi);
	return (1);
}

int	fill_struct(t_phi *phi, char **argv)
{
	if (!phi)
		return (put_message(STDERR_FILENO, "NULL pointer in fill_Structures\n"),
			0);
	phi->philo_count = ascii_to_long(argv[PHILO_COUNT]);
	if (!phi->philo_count)
		return (0);
	phi->death_time = ascii_to_long(argv[DEATH_TIME]);
	if (!phi->death_time)
		return (0);
	phi->eat_count = ascii_to_long(argv[EAT_COUNT]);
	if (!phi->eat_count)
		return (0);
	phi->eat_time = ascii_to_long(argv[EAT_TIME]);
	if (!phi->eat_time)
		return (0);
	phi->sleep_time = ascii_to_long(argv[SLEEP_TIME]);
	if (!phi->sleep_time)
		return (0);
	return (1);
}

t_phi	*init_structures()
{
	t_phi *phi;

	phi = malloc(sizeof(t_phi));
	if (!phi)
		return (put_message(STDERR_FILENO, "Error: Failed \"phi\" allocation \
			in init_structures\n"), NULL);
	*phi = (t_phi){0};
	return (phi);
}
