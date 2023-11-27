/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:20:26 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/01 12:33:03 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_categorize(const char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putpoint(va_arg(ap, unsigned long)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunsig(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(ap, int), 1));
	else if (c == 'X')
		return (ft_puthex(va_arg(ap, int), 0));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += ft_categorize(*format, ap);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
