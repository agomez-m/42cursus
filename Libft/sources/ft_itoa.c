/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:37:50 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/12 17:38:12 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
    int	count;

    count = 0;
    if (n <= 0)
        count++;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return (count);
}

char	*ft_itoa(int n)
{
    char	*ptr;
    int		i;
    int		sign;

    i = ft_count_digits(n);
    sign = 1;
    ptr = (char *)malloc(sizeof(char) * (i + 1));
    if (!ptr)
        return (NULL);
    ptr[i--] = '\0';
    if (n < 0)
    {
        ptr[0] = '-';
        sign = -1;
    }
    while (i >= 0 && ptr[i] != '-')
    {
        ptr[i--] = (n % 10) * sign + '0';
        n /= 10;
    }
    return (ptr);
}

/* convierte un entero a una cadena de caracteres */