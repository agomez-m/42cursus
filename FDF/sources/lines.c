/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:58:48 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/18 22:52:31 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_mod(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	line(t_dot in, t_dot fin, t_dot *par)
{
	float	step_col;
	float	step_row;
	float	normalizer;
	int		color;

	set_param(&in, &fin, par);
	step_col = fin.x - in.x;
	step_row = fin.y - in.y;
	normalizer = max(ft_mod(step_col), ft_mod(step_row));
	step_col /= normalizer;
	step_row /= normalizer;
	if (fin.z || in.z)
		color = 0x00FF00;
	else
		color = 0xFF0010;
	if (fin.z != in.z)
		color = 0x0000FF;
	while ((int)(in.x - fin.x) || (int)(in.y - fin.y))
	{
		mlx_pixel_put(par->mlx_ptr, par->win_ptr, in.x, in.y, color);
		in.x += step_col;
		in.y += step_row;
		if (in.x > par->win_x || in.y > par->win_y || in.y < 0 || in.x < 0)
			break ;
	}
}

void	draw_lines(t_dot **matrix)
{
	int	rows;
	int	cols;

	display_leyend(matrix[0][0]);
	rows = 0;
	while (matrix[rows])
	{
		cols = 0;
		while (1)
		{
			if (matrix[rows + 1])
				line(matrix[rows][cols], matrix[rows + 1][cols], &matrix[0][0]);
			if (!matrix[rows][cols].is_last)
				line(matrix[rows][cols], matrix[rows][cols + 1], &matrix[0][0]);
			if (matrix[rows][cols].is_last)
				break ;
			cols++;
		}
		rows++;
	}
}

/*
Si existe la fila de abajo
	-> dibuja una linea entre el punto actual y el de abajo

Si no es el ultimo punto de la fila,
	-> dibuja una linea entre el punto actual y el siguiente
*/