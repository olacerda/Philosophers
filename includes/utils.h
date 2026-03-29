/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otlacerd <otlacerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:15:06 by olacerda          #+#    #+#             */
/*   Updated: 2026/03/29 07:32:56 by otlacerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philosophers.h"

//-print.c ---------------------------------------------------------------------
void    put_message(int fd, char *string); //Choose FD to put an message

//-char.c ----------------------------------------------------------------------
int		is_numeric(char xar); // Verify if the char 'xar' is numeric
int		string_is_numeric(char *string); // Verify if all char's are numeric

//-conversor.c -----------------------------------------------------------------
char	*long_to_ascii(long number); // Careful, have MALLOC !!!
long	ascii_to_long(char *str); // Converts a string into a long number

//-string_basic.c --------------------------------------------------------------
int		string_compare(char *str1, char *str2); // Compare two strings (1 - 2)
int		string_length(char *string); // Returns the length of the string

#endif