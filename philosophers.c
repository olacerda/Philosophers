/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/31 10:03:58 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philosophers.h"
#include "execution.h"
#include "parsing.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_all *all;

	(void)argc;
	(void)argv;
	all = init_structs();
	if (!parse(argc, argv))
		return (end_structures("Error parse", 1), 1);
	if (!fill_structs(all, argv))
		return (end_structures("Error fill_structures", 1), 1);
	put_number(all->initial_time);
	dprintf(2, "philo_count: %li\n", all->param->philo_count);
	return (end_structures(NULL, 0), 0);
}
