/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:11:52 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/23 19:21:15 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_const;
	char	*dst_head;

	if (!dst && !src)
		return (dst);
	ptr_const = (char *)src;
	dst_head = dst;
	while (n)
	{
		*dst_head++ = *ptr_const++;
		n--;
	}
	return (dst);
}
