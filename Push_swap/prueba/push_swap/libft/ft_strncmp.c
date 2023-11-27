/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:45:54 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/25 12:28:50 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0' && (s1[c] == s2[c]))
	{
		c++;
	}
	if ((s1[c] != s2[c]) && (c < n))
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	return (0);
}
