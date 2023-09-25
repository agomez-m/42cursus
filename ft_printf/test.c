/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:08:44 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/25 14:37:35 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main (void)
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