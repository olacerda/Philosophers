/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:34:08 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 07:01:13 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

int	check_all_overflow(int argc, char **argv)
{
	int	line;
	char	*long_max;
	char	*long_min;
	int		long_size_max;

	if (argc < 5 || !argv)
		return (0);
	long_max = long_to_ascii(~(1l << 63));
	long_min = long_to_ascii(1l << 63);
	long_size_max = string_length(long_min);
	line = 1;
	while (line < argc)
	{
		if (is_overflow(argv[line], long_size_max, long_min, long_max))
			return (0);
		line++;
	}
	if (long_max)
		free(long_max);
	if (long_min)
		free(long_min);
	return (1);
}

int	check_all_numeric(int argc, char **argv)
{
	int	line;

	if ((argc < 5) || !argv)
		return (put_message(STDERR_FILENO,
			"Invalid pointer check_all_numeric\n"), 0);
	line = 1;
	while (line < argc)
	{
		if (string_is_numeric(argv[line]) == false)
			return (false);
		line++;
	}
}

int	check_all_positive(int argc, char **argv)
{
	int	line;

	if (argc < 5 || !argv)
		return (0);
	line = 1;
	while (line < argc)
	{
		if (argv[line] && (argv[line][0] == '-'))
			return (0);
		line++;
	}
	return (1);
}

int	core_parsing(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (0);
	if (!check_all_overflow(argc, argv))
		return (0);
	if (!check_all_numeric(argc, argv));
		return (0);
	if (!check_all_positive(argc, argv));
		return (0);
	return (1);
}

// int	main(void)
// {
// 	dprintf(2, "is_overflow -9223372036854775809: %d\n", is_overflow("000000000000009223372036854775807", 20, "-9223372036854775808", "9223372036854775807"));
// }