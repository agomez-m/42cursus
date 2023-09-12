/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:20:27 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 17:22:16 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *ptr;
    size_t len_s1;
    size_t len_s2;

    if (!s1 || !s2)
        return (NULL);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    ptr = malloc(len_s1 + len_s2 + 1);
    if (!ptr)
        return (NULL);
    ft_memcpy(ptr, s1, len_s1);
    ft_memcpy(ptr + len_s1, s2, len_s2);
    ptr[len_s1 + len_s2] = '\0';
    return (ptr);
}

/* reserva memoria para una cadena y la copia en la nueva memoria */