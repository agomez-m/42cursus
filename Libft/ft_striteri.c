/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:50:37 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/14 12:15:53 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* aplica la funcion f a cada caracter de la cadena s,
 pasandole su indice como primer argumento. 
 Cada caracter se pasa por direccion a f 
 para poder ser modificado si es necesario */
/*
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*p++ = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*myf(unsigned int n, char *s)
{
	ft_bzero(s, n);
}

#include <stdio.h>

int	main(void)
{
	char	*str;
	int		i;

	str = "Hola";
	i = 0;
	ft_striteri(str, myf(1, str));
	return (0);
}*/