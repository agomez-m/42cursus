/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:17:45 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 17:18:06 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
    char *ptr;
    int i;

    i = 0;
    ptr = malloc(ft_strlen(s1) + 1);
    if (!ptr)
        return (NULL);
    while (s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

/* reserva memoria para una cadena y la copia en la nueva memoria */