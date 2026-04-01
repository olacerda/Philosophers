/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:08:43 by otlacerd          #+#    #+#             */
/*   Updated: 2026/04/01 04:38:07 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "utils.h"

//-data_structure.c ------------------------------------------------------------
int     fill_structs(t_all *all, char **argv);//Fill structs
int     convert_argv_to_long(t_params *param, char **argv, UL start_time);//Convert strings 
int     create_arrays(t_all *all, int philo_nb);//Create 'info' arrays
int     initiate_philos(t_philo *philos, t_params *param, t_mutex *check_stop, int *stop);

//-parse.c --------------------------------------------------------------
int		parse(int argc, char **argv); // Do all the parsing.
int		string_is_numeric(char *string); // String only contain numeric char's
int		is_overflow(char *string, int max_size, char *long_min, char *long_max);

#endif
