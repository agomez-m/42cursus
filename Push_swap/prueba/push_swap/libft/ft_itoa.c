/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:06:48 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/14 11:01:35 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrsize(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_intmincase(int n, char *str)
{
	char	*nstr;
	int		i;
	char	*auxstr;

	nstr = str;
	if (n == -2147483648)
	{
		i = -1;
		auxstr = "-2147483648";
		while (++i < 12)
			nstr[i] = auxstr[i];
		return (1);
	}
	else if (n == 0)
	{
		nstr[0] = '0';
		nstr[1] = 0;
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_nbrsize(n);
	str = malloc((size + 1) * sizeof(char));
	if (!(str))
		return (0);
	if (ft_intmincase(n, str) == 1)
		return (str);
	str[size--] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[size--] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
