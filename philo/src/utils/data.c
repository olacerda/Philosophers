/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 02:19:37 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 23:16:04 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

t_all	*get_all_adress(t_all *original_all)
{
	static t_all *all;

	if (original_all != NULL)
	{
		all = original_all;
		return (NULL);
	}
	return (all);
}

int	end_structures(char *error_message)
{
	static t_all *all = NULL;

	if (!all)
		return (all = get_all_adress(NULL), 0);
	if (all->param)
		free(all->param);
	if (all->forks)
		free(all->forks);
	if (all->threads)
		free(all->threads);
	if (all->philos)
		free(all->philos);
	free(all);
	if (error_message)
		put_message(STDERR_FILENO, error_message, true);
	return (1);
}

t_all	*init_structs()
{
	t_all *all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (put_message(STDERR_FILENO,
			"Failed 'all' allocation innit_structures", true), NULL);
	*all = (t_all){0};
	get_all_adress(all);
	end_structures(NULL);
	all->param = malloc(sizeof(t_params));
	if (!all->param)
			return (end_structures(
				"Failed 'param' allocation innit_structures"), NULL);
	*all->param = (t_params){0};
	return (all);
}