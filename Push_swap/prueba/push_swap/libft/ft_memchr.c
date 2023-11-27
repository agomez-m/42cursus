/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:08:01 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/29 18:50:19 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*mys;

	i = 0;
	mys = (unsigned char *)s;
	while (n > 0)
	{
		if (mys[i] == (unsigned char)c)
			return (&mys[i]);
		i++;
		n--;
	}
	return (0);
}
