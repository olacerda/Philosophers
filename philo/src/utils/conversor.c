/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:57:37 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/05 02:38:33 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ascii_to_long(char *str)
{
	int		minus;
	long	result;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	minus = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus = true;		
		i++;
	}
	result = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = (result * 10 + (str[i] - 48));
		i++;
	}
	if (minus == true)
		result = -result;
	return (result);
}

char *long_to_ascii(UL number)
{
	char *result;
	UL	nbr;
	int		size;

	size = 0;
	nbr = number;
	while (number != 0)
	{
		size++;
		number /= 10;
	}
	// if ((nbr < 0) && ++(size))
	// 	number = true;
	result = malloc(++size * sizeof(char));
	if (!result)
		return (NULL);
	result[--size] = '\0';
	while ((--size >= 0) && (nbr != 0))
	{
		result[size] = ((nbr % 10)/** (1 - (2 * (number == true)))*/) + 48;
		nbr /= 10;
	}
	// if (number == true)
	// 	result[0] = '-';
	return (result);
}

// // ascii_to_long-------------------------------------------------------------
// int	main(void)
// {
// 	char *string = "9223372036854775807";
// 	long result;

// 	result = ascii_to_long(string);
// 	//dprintf(2, "result: %li\n", result);
// }

// // long_to_ascii ------------------------------------------------------------
// int	main(void)
// {
// 	// //dprintf(2, "teste: %d\n", -(-15 % 10));
// 	char *result;
// 	long	number = -9223372036854775808;
// 	// long	number = -12;
// 	result = long_to_ascii(number);
// 	//dprintf(2, "result: %s\n", result);
// }