/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_poi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:03:15 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/25 18:42:20 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_countpoi(unsigned long long prt)
{
	int	count;

	count = 0;
	while (prt != 0)
	{
		count++;
		prt = prt / 16;
	}
	return (count);
}

int	ft_printpoi(unsigned long long prt)
{
	if (prt >= 16)
	{
		ft_printpoi(prt / 16);
		ft_printpoi(prt % 16);
	}
	else
	{
		if (prt <= 9)
			ft_putchar_fd(prt + 48, 1);
		else
			ft_putchar_fd(prt - 10 + 'a', 1);
	}
	return (ft_countpoi(prt));
}

int	ft_putpoi(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len = len + write (1, "0x0", 3);
		return (len);
	}
	len = write (1, "0x", 2);
	len = len + ft_printpoi(ptr);
	return (len);
}
