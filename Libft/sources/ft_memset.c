/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:35:20 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 13:56:32 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *p;

    p = b;
    while (len--)
        *p++ = (unsigned char)c;
    return (b);
}

/* 
Llena el arreglo con el valor de c, hasta el tamaño len
Contenido del arreglo:
array[0] = 42
array[1] = 42
array[2] = 42
array[3] = 42
array[4] = 42
array[5] = 42
array[6] = 42
array[7] = 42
array[8] = 42
array[9] = 42
*/