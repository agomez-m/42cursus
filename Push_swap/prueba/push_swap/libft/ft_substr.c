/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:11:00 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:07 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	size_t	possub;
	size_t	lenstr;

	if (!s)
		return (0);
	lenstr = ft_strlen((char *)s);
	if (start > lenstr)
	{
		sub = malloc(1);
		*sub = 0;
		return (sub);
	}
	if (len > lenstr)
		len = lenstr - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	possub = start + len;
	i = 0;
	while (start < possub && s[start] != 0)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
