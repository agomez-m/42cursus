/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:00:32 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/25 16:47:39 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base) + 1);
	}
	else if (n < base)
	{
		ft_putchar_fd(symbols[n], 1);
		count += 1;
		return (count);
	}
	else
	{
		count = ft_print_digit(n / base, base);
		return (count + ft_print_digit (n % base, base));
	}
}
