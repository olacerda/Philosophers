/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/27 22:27:05 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "parsing.h"

int	main(int argc, char *argv[])
{
	t_all *all;

	(void)argc;
	(void)argv;
	all = init_structures();
	fill_structures(all);
	printf("all->teste: %d\n", all->teste);
	end_structures(all);
	exit(0);
}
