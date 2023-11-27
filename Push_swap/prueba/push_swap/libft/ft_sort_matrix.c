/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:55:19 by alaparic          #+#    #+#             */
/*   Updated: 2023/07/18 20:25:39 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_matrix_size(char **env)
{
	int	count;

	count = 0;
	while (*env)
	{
		count++;
		env++;
	}
	return (count);
}

char	**ft_sort_matrix(char **mat)
{
	int		i;
	int		j;
	int		len;
	char	*aux;

	i = 0;
	len = ft_get_matrix_size(mat);
	while (i < len)
	{
		j = -1;
		while (++j < (len - i - 1))
		{
			aux = mat[j];
			if (ft_strcmp(mat[j], mat[j + 1]) > 0)
			{
				aux = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = aux;
			}
		}
		i++;
	}
	return (mat);
}
