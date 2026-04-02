/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:20:26 by olacerda          #+#    #+#             */
/*   Updated: 2026/04/02 11:28:04 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "utils.h"

void    put_message(int fd, char *string, int break_line)
{
    int size;

    if ((fd < 0) || !string)
        return ;
    size = 0;
    while (string[size])
        size++;
    write(fd, string, size);
    if (break_line)
        write(fd, "\n", 1);
}

char *translate_errno(int erro)
{
    if (erro == EINVAL)
        return "Invalid argument";
    if (erro == EPERM)
        return "Operation not permitted";
    if (erro == ENOMEM)
        return "Out of memory";
    if (erro == EFAULT)
        return "Bad address";
    return (NULL);
}

void    put_number(long number)
{
    static int count;
    int is_overflow;

    is_overflow = 0;
    if (number == 1l << 63)
    {
        number++;
        is_overflow = true;
    }
    if (number < 0)
    {
        number = -number;
        write(STDOUT_FILENO, "-", 1);
    }
    count = true;
    if (number > 9 && ++(count))
        put_number(number / 10);
    write(STDOUT_FILENO,
        &(char){((number % 10 + (count == 0 && is_overflow == true))) + 48}, 1);
    if (number <= 9)
        count = 0;
}

// // put_numbers (long)
// int main(void)
// {
//     put_number(10);
//     write(1, "\n", 1);
//     put_number(-10);
//     write(1, "\n", 1);
//     put_number(0);
//     write(1, "\n", 1);
//     put_number(188);
//     write(1, "\n", 1);
//     put_number(-188);
//     write(1, "\n", 1);
//     put_number(1L << 63);
//     write(1, "\n", 1);
//     put_number(~(1L << 63));
//     write(1, "\n", 1);
//     // dprintf(2, "min: %li\n", 1L << 63);
//     // dprintf(2, "max: %li\n", ~(1L << 63));
// }
