/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:30:46 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/23 19:53:55 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (src_cpy > dst_cpy)
	{
		while (len--)
			*dst_cpy++ = *src_cpy++;
	}
	if (dst_cpy > src_cpy)
	{
		dst_cpy += len - 1;
		src_cpy += len - 1;
		while (len--)
			*dst_cpy-- = *src_cpy--;
	}
	return (dst);
}
