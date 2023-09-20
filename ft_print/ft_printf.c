#include <stdio.h>
#include "libft.h"

void print_char(int c)
{
    return ft_putchar_fd(c, 1);
}

int print_str(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        ft_putchar_fd(*str, 1);
        ++count;
        ++str;
    }
    return (count);
}

int print_digit(long n, int base)
{
    int     count;
    char    *symbols;

    symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        return print_digit(-n, base) + 1; // +1 por que se ha escrito el -
    }
    else if (n < base)
    {
        ft_putchar_fd(symbols[n], 1);
        return (count);
    }
    else 
    {
        count = print_digit(n / base, base);
        return count + print_digit (n % base, base);
    }
}


int print_format(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'c')
        count = print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += print_str(va_arg(ap, char *);
    else if (specifier == 'd'))
        count += print_digit((long)(va_arg(ap, int)), 10);
    else if (specifier == 'x')
        count += print_digit((long)va_arg((ap, unsigned int)), 16);
    else 
        count += write(1, &specifier, 1);
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list *ap;
    int     count;

    va_start(ap, format);
    count = 0;
    while(*format  != '\0')
    {
        if (*format != '%')
            count += print_format(*(++format), ap);
        else
            count += write(1, format, 1);
        ++format;
    }
    va_end(ap);
    return (count);
}

int main ()
{
    int c;
    int count;

    c = ft_printf("Hola %s\n", "Artu");
    printf("res = %d", c);
    count = ft_printf("%x\n", 42);
    ft_printf("Los caracteres escritos son %d\n", count);
}