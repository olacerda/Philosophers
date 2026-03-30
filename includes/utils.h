/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:15:06 by olacerda          #+#    #+#             */
/*   Updated: 2026/03/30 15:39:16 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef UTILS_H
# define UTILS_H

# include "philosophers.h"

//-print.c ---------------------------------------------------------------------
void    put_message(int fd, char *string, int break_line);//Choose FD to message
void    put_number(long number);
char    *translate_errno(int erro);

//-char.c ----------------------------------------------------------------------
int		is_numeric(char xar); // Verify if all char's are numeric

//-conversor.c -----------------------------------------------------------------
char	*long_to_ascii(long number); // Careful, have MALLOC !!!
long	ascii_to_long(char *str); // Converts a string into a long number

//-string_basic.c --------------------------------------------------------------
int		string_compare(char *str1, char *str2); // Compare two strings (1 - 2)
int		string_length(char *string); // Returns the length of the string
int     memory_zero(void *pointer, long size); // Set all bytes of pointer to 0

//-free.c ---------------------------------------------------------------------0
int     free_array_pointer(void **array, int size); // Size of array, not bytes!

#endif