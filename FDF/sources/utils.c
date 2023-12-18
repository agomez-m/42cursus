/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:48:37 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/18 12:07:39 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

int	ft_wordcounter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void	display_leyend(t_dot matrix)
{
	char	*menu;

	menu = "Welcome to FDF by AGOMEZ-M";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 10, 0xFF00AA, menu);
	menu = "ARROWS: move picture";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 25, 0xCCFF00, menu);
	menu = "press + - to zoom";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 40, 0xCCFF00, menu);
	menu = "number 5 and SPACE: 3d/2d mode";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 55, 0xCCFF00, menu);
	menu = "numbers 4 and 6: rotation";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 70, 0xCCFF00, menu);
	menu = "numbers 8 and 2: z-scale";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 85, 0xCCFF00, menu);
	menu = "press 'f' to full screen mode";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 100, 0xCCFF00, menu);
	menu = "press 'a' 's' / 'z' 'x' to change screen size";
	mlx_string_put(matrix.mlx_ptr, matrix.win_ptr, 600, 115, 0xCCFF00, menu);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
