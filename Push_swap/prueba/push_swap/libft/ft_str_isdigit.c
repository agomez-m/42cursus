/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:40:01 by alaparic          #+#    #+#             */
/*   Updated: 2023/08/16 12:00:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_isdigit(char *str)
{
	int	n;

	n = 0;
	if (str[n] == '-' || str[n] == '+')
		n++;
	while (str[n])
	{
		if (!ft_isdigit(str[n]))
			return (0);
		n++;
	}
	return (1);
}
