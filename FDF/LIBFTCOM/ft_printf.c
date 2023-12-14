/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:00:50 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 14:08:21 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'i')
		count += ft_print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'X')
		count += ft_print_digitx((long)(va_arg(ap, unsigned int)), 16);
	else if (specifier == 'u')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), 10);
	else if (specifier == 'p')
		count += ft_putpoi(va_arg(ap, unsigned long long));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	if (!format)
		return (-1);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += ft_print_char(*format);
		++format;
	}
	va_end(ap);
	return (count);
}
