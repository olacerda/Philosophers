/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 22:08:43 by otlacerd          #+#    #+#             */
/*   Updated: 2026/03/30 15:58:44 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PARSING_H
# define PARSING_H

# include "philosophers.h"

//-data_structure.c ------------------------------------------------------------
int     fill_structs(t_all *all, char **argv);//Fill structs
int     convert_argv_to_long(t_params *param, char **argv);//Convert strings 
int     create_arrays(t_info *inf, int philo_nb);//Create 'info' arrays

//-data_structure_utils.c ------------------------------------------------------
t_all	*init_structures(); // Allocate and set to 0 all structures
int		end_structures(char *error_message, int status); // Free all
t_all	*get_all_adress(t_all *original_all); // To have global reference of all

//-parse.c --------------------------------------------------------------
int		parse(int argc, char **argv); // Do all the parsing.
int		string_is_numeric(char *string); // String only contain numeric char's
int		is_overflow(char *string, int max_size, char *long_min, char *long_max);

#endif
