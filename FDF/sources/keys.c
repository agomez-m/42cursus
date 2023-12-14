/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:15:44 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 21:41:30 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	true_key(int key)
{
	return (key == 24 || key == 69 || key == 27 || key == 78 || \
	key == 91 || key == 28 || key == 84 || key == 19 || \
	key == '~' || key == '}' || key == '{' || key == '|' || \
	key == 87 || key == 23 || key == 86 || key == 21 || \
	key == 49 || key == 88 || key == 22);
}

void	do_key(int key, t_dot **matrix)
{
	if (key == 24 || key == 69)
		matrix[0][0].scale += 3;
	else if (key == 27 || key == 78)
		matrix[0][0].scale -= 3;
	else if (key == 91 || key == 28)
		matrix[0][0].z_scale += 1;
	else if (key == 84 || key == 19)
		matrix[0][0].z_scale -= 1;
	else if (key == '~')
		matrix[0][0].shift_y -= 10;
	else if (key == '}')
		matrix[0][0].shift_y += 10;
	else if (key == '{')
		matrix[0][0].shift_x -= 10;
	else if (key == '|')
		matrix[0][0].shift_x += 10;
	else if (key == 49 || key == 87 || key == 23)
		matrix[0][0].is_isometric = !matrix[0][0].is_isometric;
	else if (key == 86 || key == 21)
		matrix[0][0].angle += 0.05;
	else if (key == 88 || key == 22)
		matrix[0][0].angle -= 0.05;
}

int	deal_key(int key, t_dot **matrix)
{
	if (true_key(key))
	{
		mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		do_key(key, matrix);
		display_leyend(matrix[0][0]);
		draw_lines(matrix);
	}
	if (key == 6 || key == 7 || key == 0 || key == 1 || key == 3)
		new_window(key, matrix);
	if (key == '5')
	{
		mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
