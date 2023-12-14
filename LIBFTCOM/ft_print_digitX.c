/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digitX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:48:36 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 14:08:06 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_digitx(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digitx(-n, base) + 1);
	}
	else if (n < base)
	{
		ft_putchar_fd(symbols[n], 1);
		count += 1;
		return (count);
	}
	else
	{
		count = ft_print_digitx(n / base, base);
		return (count + ft_print_digitx(n % base, base));
	}
}
