/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:57:55 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/05 14:50:52 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_buffer(char *buffer, char *new_str)
{
	char	*aux;

	if (!new_str)
		aux = NULL;
	else
		aux = gnl_strjoin(buffer, new_str);
	free(buffer);
	return (aux);
}

static char	*read_line(int fd, char *buffer)
{
	char	*aux;
	int		len;
	char	*point;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	aux = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	len = 1;
	while (len != 0)
	{
		point = aux;
		while (*point)
			*point++ = '\0';
		len = read(fd, aux, BUFFER_SIZE);
		buffer = join_buffer(buffer, aux);
		if (gnl_strchr(aux, '\n') != NULL)
			break ;
	}
	free(aux);
	return (buffer);
}

static char	*copy_to_str(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i++;
	while (i-- != 0)
		str[i] = buffer[i];
	return (str);
}

static char	*set_buffer(char *buffer)
{
	char	*aux;
	char	*str;
	int		i;

	aux = gnl_memchr(buffer, '\n', ft_strlen(buffer));
	if (!aux)
	{
		free(buffer);
		return (NULL);
	}
	aux++;
	str = ft_calloc(ft_strlen(aux) + 1, sizeof(char));
	i = -1;
	while (i++ < (int) ft_strlen(str))
		str[i] = aux[i];
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = read_line(fd, buffer[fd]);
	str = copy_to_str(buffer[fd]);
	buffer[fd] = set_buffer(buffer[fd]);
	return (str);
}
