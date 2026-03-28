/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:19:01 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/28 04:27:16 by olacerda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

int	end_structures(t_all *all)
{
	if (!all)
		return (put_message(STDERR_FILENO, "NULL pointer in end_Structures\n"),
			0);
	free(all);
	return (1);
}

int	fill_structures(t_all *all)
{
	if (!all)
		return (put_message(STDERR_FILENO, "NULL pointer in fill_Structures\n"),
			0);
	all->teste = 0;
	return (1);
}

t_all	*init_structures()
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (put_message(STDERR_FILENO, "Error: Failed \"all\" allocation \
			in init_structures\n"), NULL);
	*all = (t_all){0};
	return (all);
}
