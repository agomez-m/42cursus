/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:39:52 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 16:40:11 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;

    i = ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char)c)
            return ((char *)s + i);
        i--;
    }
    return (NULL);
}

/* busca un caracter en una cadena y devuelve un puntero a la ultima ocurrencia de c en s */        