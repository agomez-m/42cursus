/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:18:49 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/20 20:27:32 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (NULL == dst && 0 == dstsize)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (dest_len >= dstsize)
		return (src_len + dstsize);
	else
		dstsize -= dest_len;
	ft_strlcpy(dst + dest_len, src, dstsize);
	return (dest_len + src_len);
}

/* concatena la cadena src en la cadena dst, 
   hasta el tamaño dstsize - 1. 
   La función devuelve la longitud de 
   la cadena src + la longitud de la cadena dst.
*/
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*src;
	char	*dst;
	size_t	dstsize;

	src = "Hola";
	dst = "Adios";
	dstsize = 1;
	printf("%zu\n", ft_strlcat(dst, src, dstsize));
	printf("%zu\n", strlcat (dst, src, dstsize));
	return (0);
}*/