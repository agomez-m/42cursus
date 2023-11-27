/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:22:35 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/25 11:35:50 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		i;
	int		s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s1_cpy = malloc(s1_len + 1 * sizeof(char));
	if (!s1_cpy)
		return (0);
	while (i < s1_len)
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}
