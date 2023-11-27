/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:21:44 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/01 12:44:12 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	int		len;

	if (!c)
		return (ft_putstr("(null)"));
	len = 0;
	while (c[len])
		len += ft_putchar(c[len]);
	return (len);
}
