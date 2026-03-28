/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:19:01 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/27 22:33:36 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	end_structures(t_all *all)
{
	if (!all)
		return (0);
	free(all);
	return (1);
}

int	fill_structures(t_all *all)
{
	if (!all)
		return (0);
	all->teste = 0;
	return (1);
}

t_all	*init_structures()
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	*all = (t_all){0};
	return (all);
}
