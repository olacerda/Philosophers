/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:53:07 by olacerda          #+#    #+#             */
/*   Updated: 2026/03/31 06:55:19 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	end_structures(char *error_message, int status)
{
	static t_all *all = NULL;

	if (!all)
		return (all = get_all_adress(NULL), 0);
	if (all->param)
		free(all->param);
	if (all->info)
		free(all->info);
	free(all);
	if (error_message)
		put_message(STDERR_FILENO, error_message, true);
	exit (status);
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
	end_structures(NULL, 0);
	all->info = malloc(sizeof(t_info));
	if (!all->info)
		return (end_structures(
			"Failed 'info' allocation in init_structs", 1), NULL);
	*all->info = (t_info){0};
	all->param = malloc(sizeof(t_params));
	if (!all->param)
			return (end_structures(
				"Failed 'param' allocation innit_structures", 1), NULL);
	*all->param = (t_params){0};
	return (all);
}
