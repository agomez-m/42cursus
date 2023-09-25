/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:08:44 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/25 18:48:14 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		c;
	int		count;
	int		countf;
	int		countj;
	int		countfj;
	char	a;
	int		b;
	int		z;
	int		y;

	a = 'Y';
	//CHAR
	b = ft_printf("FT       = %c\n", a);
	ft_printf("FT       = %c\n", b);
	y = printf("ORIGINAL = %c\n", a);
	printf("ORIGINAL = %c\n", y);
	write (1, "\n", 1); 
	//STRING
	c = ft_printf("FT       = %s\n", "Artu");
	ft_printf("FT       = %d\n", c);
	z = printf("ORIGINAL = %s\n", "Artu");
	printf("ORIGINAL = %d\n", z);
	ft_printf("t1: %s\n", (char *)NULL);
	printf("T1: %s\n", (char *)NULL);
	write (1, "\n", 1);
	//INTEGER D
	count = ft_printf("FT       = %d\n", -4200000);
	ft_printf("FT       = %d\n", count);
	countf = printf("ORIGINAL = %d\n", -4200000);
	printf("ORIGINAL = %d\n", countf);
	write (1, "\n", 1);
	//INTEGER I
	count = ft_printf("FT       = %i\n", -4200000);
	ft_printf("FT       = %i\n", count);
	countf = printf("ORIGINAL = %i\n", -4200000);
	printf("ORIGINAL = %i\n", countf);
	write (1, "\n", 1);
	//hex
	countj = ft_printf("FT       = %x\n", 420000);
	ft_printf("FT       = %d\n", countj);
	countfj = printf("ORIGINAL = %x\n", 420000);
	printf("ORIGINAL = %d\n", countfj);
	write(1, "\n", 1);
	//HEX
	countj = ft_printf("FT       = %X\n", 42000);
	ft_printf("FT       = %d\n", countj);
	countfj = printf("ORIGINAL = %X\n", 42000);
	printf("ORIGINAL = %d\n", countfj);
	write(1,"\n",1);
	//UNS
	//countj = ft_printf("FT       = %u\n", 42000);
	//ft_printf("FT       = %u\n", countj);
	countfj = printf("ORIGINAL = %u\n", -42000);
	printf("ORIGINAL = %u\n", countfj);
	countfj = printf("ORIGINAL = %u\n", 42000);
	printf("ORIGINAL = %u\n", countfj);
	c = ft_printf("FT       = %u\n", -10);
	printf("%d\n", c);
	c = printf("ORIGINAL = %u\n", -10);
	printf("%d\n", c);
	write(1, "\n", 1);

	printf(" %p %p \n", 0, 0);
	ft_printf(" %p %p \n", 0, 0);
	printf(" %p \n", 0);
	ft_printf(" %p \n", 0);


	
}
