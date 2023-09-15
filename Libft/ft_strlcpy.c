/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:12:29 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/13 20:44:02 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/* copia la cadena src en dst, hasta el tamaño dstsize
   la función copia hasta dstsize - 1 caracteres de la cadena src 
   en la cadena dst, NUL-terminando la cadena resultante en dst. 
   Si dstsize es 0, la cadena de destino no se NUL-termina. 
   Si el tamaño de la cadena de origen es mayor o igual que dstsize, 
   la cadena de origen no se NUL-termina. 
   La función devuelve la longitud de la cadena src.
*/