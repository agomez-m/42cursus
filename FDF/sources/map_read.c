/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:14:43 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 20:02:32 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_to_dots(char *line, t_dot **matrix, int y)
{
	char	**dots;
	int		x;

	dots = ft_split(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix[y][x].z = ft_atoi(dots[x]);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix[y][--x].is_last = 1;
	return (x);
}

t_dot	**alloc_map_size(char *file)
{
	t_dot	**new;
	int		cols;
	int		rows;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if ((fd) <= 0)
		ft_error("file does not exist");
	get_next_line(fd, &line);
	cols = ft_wordcounter(line, ' ');
	free(line);
	rows = 0;
	while (get_next_line(fd, &line) > 0)
	{
		rows++;
		free(line);
	}
	free(line);
	new = (t_dot **)malloc(sizeof(t_dot *) * (++rows + 1));
	while (rows > 0)
		new[--rows] = (t_dot *)malloc(sizeof(t_dot) * (cols + 1));
	close(fd);
	return (new);
}

t_dot	**read_map(char *file)
{
	t_dot	**matrix;
	int		fd;
	char	*line;
	int		y;

	matrix = alloc_map_size(file);
	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("file does not exist");
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_to_dots(line, matrix, y);
		y++;
	}
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}
