
#include "libft.h"

int ft_isalpha(int c)
{
    if((c >= 65 && c<=90) || (c >= 97 && c<=122))
    {
        return (1);
    }
    return (0);
}

/* Devuelve un entero, 0 si no es una letra y 1 si lo es*/