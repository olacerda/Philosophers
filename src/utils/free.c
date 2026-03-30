/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olacerda <olacerda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:47:02 by olacerda          #+#    #+#             */
/*   Updated: 2026/03/30 10:53:47 by olacerda         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "utils.h"

int free_array_pointer(void **array, int size)
{
    int index;

    if (!array || size <= 0)
        return (0);
    index = 0;
    while (index < size)
    {
        free(array[index]);
        index++;
    }
    free(array);
    return (1);
}
