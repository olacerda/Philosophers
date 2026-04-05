/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:47:05 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/05 02:38:33 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	string_compare(char *str1, char *str2)
{
	int	index;

	if (!str1 || !str2)
		return (0);
	index = 0;
	while (str1[index] && str2[index] && (str1[index] == str2[index]))
		index++;
	return (str1[index] - str2[index]);
}

int	string_length(char *string)
{
	int	size;

	if (!string)
		return (FAIL);
	size = 0;
	while (string[size])
		size++;
	return (size);
}

int	memory_zero(void *pointer, long size)
{
	int	index;

	if (!pointer || size <= 0)
		return (0);
	index = 0;
	while (index < size)
	{
		((char *)pointer)[index] = 0;
		index++;
	}
	return (1);
}

int	is_numeric(char xar)
{
	if (!xar)
		return (0);
	if (xar < '0' || xar > '9')
		return (0);
	return (1);
}

// int	main(void)
// {
// 	char *string1 = "Ai";
// 	char *string2 = "Ai tudo bem";

// 	//dprintf(2, "result: %d\n", string_compare(string1, string2));
// }