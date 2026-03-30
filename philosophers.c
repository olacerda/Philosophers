/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 21:58:30 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/30 02:14:00 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	dprintf(2, "main branch\n");
	fill_struct(phi,argv);
	end_structures(phi);
	exit(0);
}
