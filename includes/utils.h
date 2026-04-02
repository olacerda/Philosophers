/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:15:06 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/02 14:09:00 by olacerda         ###   ########.fr       */
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

//-time.c ----------------------------------------------------------------------
UL		get_full_timeofday();
int		sleep_until(unsigned long time);//Perform continuous short sleeps

//-data.c ----------------------------------------------------------------------
t_all	*init_structs(); // Allocate and set to 0 all structures
int		end_structures(char *error_message, int status); // Free all
t_all	*get_all_adress(t_all *original_all); // To have global reference of all

#endif