/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:09:55 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/26 19:52:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;
	size_t			i;

	s1cpy = (unsigned char *)s1;
	s2cpy = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1cpy[i] != s2cpy[i])
			return (s1cpy[i] - s2cpy[i]);
		i++;
	}
	return (0);
}
