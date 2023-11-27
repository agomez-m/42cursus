/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:16:41 by alaparic          #+#    #+#             */
/*   Updated: 2022/09/29 19:10:30 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len_s;
	char	*str;

	str = (char *)s;
	len_s = ft_strlen(str);
	while (len_s >= 0)
	{
		if (str[len_s] == (unsigned char)c)
			return (&str[len_s]);
		len_s--;
	}
	return (0);
}
