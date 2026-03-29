/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:08:43 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/29 07:38:39 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "philosophers.h"

//-data_structure.c ------------------------------------------------------------
int		end_structures(t_phi *phi); // Free all structures
int		fill_struct(t_phi *phi, char **argv); // Fill all structs
t_phi	*init_structures(); // Allocate and set to 0 all structures

//-core_parsing.c --------------------------------------------------------------
int		core_parsing(int argc, char **argv); // Do all the parsing.
int		check_all_positive(int argc, char **argv); // Only positive nb on argv
int		check_all_overflow(int argc, char **argv); // Verify overflow on argv
int		check_all_numeric(int argc, char **argv); // Only numeric char's on argv

//-parsing_utils.c -------------------------------------------------------------
int		string_is_numeric(char *string); // String only contain numeric char's
int		is_overflow(char *string, int max_size, char *long_min, char *long_max);

#endif
