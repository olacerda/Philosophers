/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 05:47:05 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 06:44:06 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	string_compare(char *str1, char *str2)
{
	int	index;

	if (!str1 || !str2)
		return (-1);
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

// int	main(void)
// {
// 	char *string1 = "Ai";
// 	char *string2 = "Ai tudo bem";

// 	dprintf(2, "result: %d\n", string_compare(string1, string2));
// }