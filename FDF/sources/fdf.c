/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:37:08 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/19 00:49:53 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	param_default(t_dot *param)
{
	param->scale = 10;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.8;
	param->win_x = 1000;
	param->win_y = 500;
	param->shift_x = 300;
	param->shift_y = 150;
	param->mlx_ptr = mlx_init();
	param->win_ptr = \
	mlx_new_window(param->mlx_ptr, \
		param->win_x, \
		param->win_y, \
		"FDF by AG");
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc != 2)
		ft_error("To display a map: ./fdf MAP.fdf");
	matrix = read_map(*++argv);
	param_default(&matrix[0][0]);
	draw_lines(matrix);
	mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
	mlx_loop(matrix[0][0].mlx_ptr);
}
/*
leaks:
ejecutar ./fdf mapa.fdf
ejecutat en otra terminal leaks -q -- pid_of_fdf_process
para hayar el pid: 	ps -a | grep fdf
					ps aux | grep fdf

mlx_init(); empieza la conexion con el servidor grafico 
y devuelve un puntero a la conexion. Arranca la maquina

mlx_new_window(); crea una ventana y devuelve un puntero
 a ella

 mlx_key_hook(); registra una funcion que se ejecuta cuando se
 presiona una tecla
 
 mlx_loop(); arranca el bucle de eventos de la ventana
 
 mlx_destroy_window(); destruye la ventana
 
 mlx_clear_window(); limpia la ventana
 
 mlx_pixel_put(); pone un pixel en la ventana

*/