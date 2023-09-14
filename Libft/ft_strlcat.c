/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:18:49 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/14 11:51:16 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
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