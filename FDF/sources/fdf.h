/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:16:08 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:44:31 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../LIBFTCOM/ft_printf.h"
# include "../LIBFTCOM/get_next_line.h"
# include "../LIBFTCOM/libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# define PRM matrix[0][0]

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_dot;

t_dot			**map_read(char *file_name);

void			isometric(t_dot *dot, double angle);
void			draw(t_dot **matrix);
int				deal_key(int key, t_dot **matrix);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
void			print_menu(t_dot param);
void			ft_error(char *msg);
void			new_window(int key, t_dot **matrix);

#endif