/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:58:42 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/20 11:50:06 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

/* copia el contenido de src a dst hasta el tamaño n 
  la principal diferencia entre memcpy y memmove 
  es su manejo de la solapamiento de memoria.
  Si estás seguro de que no hay solapamiento entre 
  las áreas de origen y destino, puedes usar memcpy, 
  que generalmente es más eficiente. Sin embargo, 
  si no estás seguro o si sabes que existe la posibilidad 
  de solapamiento, es más seguro utilizar memmove 
  para evitar problemas de corrupción de datos.
*/