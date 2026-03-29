/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 06:52:25 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 07:39:14 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

int	is_overflow(char *string, int max_size, char *long_min, char *long_max)
{
	int	str_size;

	if (!string)
		return (0);
	str_size = 0;
	if (string[str_size] == '+')
		string++;
	while (*string == '0')
		string++;
	while (string[str_size])
		str_size++;
	if (str_size > max_size)
		return (true);
	if (str_size == max_size)
		return (string_compare(string, long_min));
	return (string_compare(string, long_max));
}

int	string_is_numeric(char *string)
{
	int	index;

	if (!string)
		return (0);
	index = 0;
	if (*string == '+' || *string == '-')
		string++;
	while (*string == '0')
		string++;
	while (string[index])
	{
		if (is_numeric(string[index]) == false)
			return (false);
		index++;
	}
	return (true);
}