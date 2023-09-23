#include <stdio.h>
#include "./ft_srcs/libft.h"

int print_char(int c)
{
    ft_putchar_fd(c, 1);
    return (1);
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
    count = 0;
    if (n < 0)
    {
        write(1, "-", 1);
        return print_digit(-n, base) + 1; // +1 por que se ha escrito el -
    }
    else if (n < base)
    {
        ft_putchar_fd(symbols[n], 1);
        count += 1;
        return (count);
    }
    else 
    {
        count = print_digit(n / base, base);
        //printf("\nel count = %d\n", count);
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
        count += print_str(va_arg(ap, char *));
    else if (specifier == 'd')
        count += print_digit((long)(va_arg(ap, int)), 10);
    else if (specifier == 'x')
        count += print_digit((long)(va_arg(ap, unsigned int)), 16);
    else 
        count += write(1, &specifier, 1);
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count;

    va_start(ap, format);

    count = 0;
    while(*format  != '\0')
    {
        if (*format == '%')
            count += print_format(*(++format), ap);
        else
            count += print_char(*format);
        ++format;
    }
    va_end(ap);
    return (count);
}

int main ()
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
}