/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:42:20 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 17:50:02 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *ptr;
    int i;

    if (!s || !f)
        return (NULL);
    ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (s[i])
    {
        ptr[i] = f(i, s[i]);
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

/* aplica una funcion a cada caracter de una cadena 
A cada carácter de la string ’s’, aplica la
función ’f’ dando como parámetros el índice de cada
carácter dentro de ’s’ y el propio carácter. Genera
una nueva string con el resultado del uso sucesivo
de ’f’*/