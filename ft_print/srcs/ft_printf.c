/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:00:50 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/25 14:09:11 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../ft_printf.h"

int ft_print_format(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'c')
        count = ft_print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += ft_print_str(va_arg(ap, char *));
    else if (specifier == 'd')
        count += ft_print_digit((long)(va_arg(ap, int)), 10);
    else if (specifier == 'x')
        count += ft_print_digit((long)(va_arg(ap, unsigned int)), 16);
    else 
        count += write(1, &specifier, 1);
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;

    va_start(ap, format);
    if (!format)
        return (-1);
    count = 0;
    while(*format  != '\0')
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
/*
int main (void)
{
    int     c;
    int     count;
    int     countf;
    int     countj;
    int     countfj;
    char    a = 'Y';
    int     b;
    int     z;
    int     y;
    
    b = ft_printf("FT       = %c\n", a);
    ft_printf("FT       = %c\n", b);
    y = printf("ORIGINAL = %c\n", a);
    printf("ORIGINAL = %c\n", y);
    write (1, "\n", 1);
    c = ft_printf("FT       = %s\n", "Artu");
    ft_printf("FT       = %d\n", c);
    z = printf("ORIGINAL = %s\n", "Artu");
    printf("ORIGINAL = %d\n", z);
    write (1, "\n", 1);
    count = ft_printf("FT       = %d\n", -4200000);
    ft_printf("FT       = %d\n", count);
    countf = printf("ORIGINAL = %d\n", -4200000);
    printf("ORIGINAL = %d\n", countf);
    write (1, "\n", 1);
    countj = ft_printf("FT       = %x\n", 4200000);
    ft_printf("FT       = %d\n", countj);
    countfj = printf("ORIGINAL = %x\n", 4200000);
    printf("ORIGINAL = %d\n", countfj);
}*/