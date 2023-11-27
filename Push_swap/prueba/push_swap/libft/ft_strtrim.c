/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:58:02 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/26 13:40:58 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new_src;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start])
	{
		if (!ft_strchr(set, s1[start]))
			break ;
		start++;
	}
	while (end > start)
	{
		if (!ft_strchr(set, s1[end]))
			break ;
		end--;
	}
	new_src = (char *)ft_calloc((end - start + 2), sizeof(char));
	if (new_src)
		ft_strlcpy(new_src, s1 + start, (end - start + 2));
	return (new_src);
}
