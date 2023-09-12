/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:57:14 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 16:57:38 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *p;

    p = (unsigned char *)s;
    while (n--)
    {
        if (*p == (unsigned char)c)
            return (p);
        p++;
    }
    return (NULL);
}

/* busca el caracter c en los primeros n bytes de la cadena s */