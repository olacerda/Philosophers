/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 07:28:13 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "parsing.h"

int	main(int argc, char *argv[])
{
	t_phi *phi;

	(void)argc;
	(void)argv;
	phi = init_structures();
	if (!core_parsing(argc, argv))
		return (/*verificar mensagem*/end_structures(phi), 1);
	fill_struct(phi);
	end_structures(phi);
	exit(0);
}
