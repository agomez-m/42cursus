/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:05:59 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 14:11:52 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d;
    unsigned char *s;

    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (!dst && !src)
        return (NULL);
    if (s < d)
        while (len--)
            d[len] = s[len];
    else
        ft_memcpy(d, s, len);
    return (dst);
}

/* copia el contenido de src a dst hasta el tamaño len 
  la principal diferencia entre memcpy y memmove 
  es su manejo de la solapamiento de memoria.
  Si estás seguro de que no hay solapamiento entre 
  las áreas de origen y destino, puedes usar memcpy, 
  que generalmente es más eficiente. Sin embargo, 
  si no estás seguro o si sabes que existe la posibilidad 
  de solapamiento, es más seguro utilizar memmove 
  para evitar problemas de corrupción de datos.
*/   