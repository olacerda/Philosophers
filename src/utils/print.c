/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 04:20:26 by olacerda          #+#    #+#             */
/*   Updated: 2026/03/30 02:26:35 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "utils.h"

void    put_message(int fd, char *string)
{
    int size;

    if ((fd < 0) || !string)
        return ;
    size = 0;
    while (string[size])
        size++;
    write(fd, string, size);
    dprintf(2, "hello baby\n");
}
