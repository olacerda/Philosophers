/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:34:08 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/02 23:47:47 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	if (str_size < max_size)
		return (false);
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
			return (0);
		index++;
	}
	return (1);
}


int	parse(int argc, char **argv)
{
	int	line;
	char	*long_max;
	char	*long_min;
	int		long_size_max;

	if (argc != 5 && argc != 6)
		return (0);
	long_max = long_to_ascii((UL)-1);
	long_min = long_to_ascii(1l << 63);
	long_size_max = string_length(long_min);
	line = 1;
	while (line < argc)
	{ // --------------------------------------- Tem um "certo" limite de 200 philosofos? olhar depois
		if (!string_is_numeric(argv[line]))
			return (free(long_max), free(long_min), 0);
		if (is_overflow(argv[line], long_size_max, long_min, long_max) > 0)
			return (free(long_max), free(long_min), 0);
		if (!argv[line] || !argv[line][0] || (argv[line][0] == '-'))
			return (free(long_max), free(long_min), 0);
		line++;
	}
	free(long_max);
	free(long_min);
	return (1);
}

// int	main(void)
// {
// 	dprintf(2, "is_overflow -9223372036854775809: %d\n", is_overflow("000000000000009223372036854775807", 20, "-9223372036854775808", "9223372036854775807"));
// }