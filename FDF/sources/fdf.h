/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:16:08 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 21:41:08 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../LIBFTCOM/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

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

t_dot			**read_map(char *file);
void			ft_error(char *msg);
int				ft_wordcounter(char const *str, char c);
void			draw_lines(t_dot **matrix);
void			display_leyend(t_dot matrix);
int				max(int a, int b);
int				min(int a, int b);
int				deal_key(int key, t_dot **matrix);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
void			new_window(int key, t_dot **matrix);

#endif