/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:36:02 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 17:41:48 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_count_words(char const *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            count++;
            while (s[i] != c && s[i])
                i++;
        }
        else
            i++;
    }
    return (count);
}

static int ft_wordlen(char const *s, char c)
{
    int i;

    i = 0;
    while (s[i] != c && s[i])
        i++;
    return (i);
}

static char **ft_free(char **ptr, int i)
{
    while (i >= 0)
    {
        free(ptr[i]);
        i--;
    }
    free(ptr);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    char **ptr;
    int i;
    int j;
    int k;

    if (!s)
        return (NULL);
    ptr = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
    if (!ptr)
        return (NULL);
    i = -1;
    j = 0;
    while (++i < ft_count_words(s, c))
    {
        while (s[j] == c)
            j++;
        ptr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(s + j, c) + 1));
        if (!ptr[i])
            return (ft_free(ptr, i));
        k = 0;
        while (s[j] != c && s[j])
            ptr[i][k++] = s[j++];
        ptr[i][k] = '\0';
    }
    ptr[i] = NULL;
    return (ptr);
}

/* reserva memoria para una matriz de cadenas y la copia en la nueva memoria 
Reserva (utilizando malloc(3)) un array de strings
resultante de separar la string ’s’ en substrings
utilizando el caracter ’c’ como delimitador. El
array debe terminar con un puntero NULL.*/