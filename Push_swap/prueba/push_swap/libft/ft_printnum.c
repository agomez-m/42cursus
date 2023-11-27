/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:45:33 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/01 12:34:55 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putchar('-');
		len += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_puthex(unsigned int n, int flag)
{
	char	*chars;
	int		len;

	len = 0;
	if (flag == 1)
		chars = "0123456789abcdef";
	else
		chars = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_puthex(n / 16, flag);
		len += ft_puthex(n % 16, flag);
	}
	else
		len += ft_putchar(chars[n]);
	return (len);
}

int	ft_putunsig(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunsig(n / 10);
		len += ft_putunsig(n % 10);
	}
	else
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_putpoint(unsigned long n)
{
	char	*chars;
	int		len;

	len = 0;
	chars = "0123456789abcdef";
	if (n < 16)
	{
		len += ft_putstr("0x");
		len += ft_putchar(chars[n]);
		return (len);
	}
	len += ft_putpoint(n / 16);
	len += ft_putchar(chars[n % 16]);
	return (len);
}
