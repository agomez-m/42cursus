/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:36:02 by agomez-m          #+#    #+#             */
/*   Updated: 2023/09/13 11:52:26 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char c)
{
	int		i;
	int		timer;

	i = 0;
	timer = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			timer++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (timer);
}

static int	ft_wordlen(char const *str, char c)
{
	int		i;
	int		timer2;

	i = 0;
	timer2 = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		timer2++;
		i++;
	}
	return (timer2);
}

char	*ft_strnew(size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(sizeof(*temp) * (size + 1));
	if (!temp)
		return (NULL);
	if (temp)
	{
		while (i <= size)
		{
			temp[i] = '\0';
			i++;
		}
	}
	return (temp);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**strmagic;
	int		i;
	int		i2;
	int		i3;

	strmagic = (char **)malloc(sizeof(*strmagic) * (ft_wordcount(s, c) + 1));
	if (!s || !(strmagic))
		return (0);
	i = -1;
	i2 = 0;
	while (++i < ft_wordcount(s, c))
	{
		i3 = 0;
		strmagic[i] = ft_strnew(ft_wordlen(&s[i2], c) + 1);
		if (!(strmagic))
			strmagic[i] = NULL;
		while (s[i2] == c)
			i2++;
		while (s[i2] != c && s[i2])
			strmagic[i][i3++] = s[i2++];
		strmagic[i][i3] = '\0';
	}
	strmagic[i] = 0;
	return (strmagic);
}

/* reserva memoria para una matriz de cadenas y la copia en la nueva memoria 
Reserva (utilizando malloc(3)) un array de strings
resultante de separar la string ’s’ en substrings
utilizando el caracter ’c’ como delimitador. El
array debe terminar con un puntero NULL.*/