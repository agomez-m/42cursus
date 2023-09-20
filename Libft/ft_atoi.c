/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:12:24 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/20 14:00:14 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

/* convierte el string str en un entero int 
tu implementación de ft_atoi debería funcionar 
de manera similar a atoi en la mayoría de los casos, 
convirtiendo una cadena en un número entero. Sin embargo, 
ten en cuenta que tu implementación no maneja 
desbordamiento (overflow) o números fuera del rango de int*/
/*
#include <stdio.h>
int main (void)
{
	char str[] = "-2147483649";
	printf("%d\n", ft_atoi(str));
	return (0);
}*/