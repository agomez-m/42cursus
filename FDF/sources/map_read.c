/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:14:43 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:49:23 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	**read_map(char *file)
{
	t_dot	**matrix;
	int		fd;
	char	*line;
	int		y;

	matrix = memory_allocete(file);
	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("file does not exist");
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		get_dots_from_line(line, matrix, y);
		y++;
	}
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}