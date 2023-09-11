
#include "libft.h"

int ft_isdigit(int c)
{
    if((c >= 48 && c<= 57))
    {
        return (1);
    }
    return (0);
}

/* Devuelve un entero, 0 si no es un numero y 1 si lo es*/