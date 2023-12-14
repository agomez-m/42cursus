/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:19:35 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/14 20:26:35 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_arr	*newlist(const int fd)
{
	t_arr	*new;

	new = (t_arr *)malloc(sizeof(t_arr));
	if (!(new))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

static char	*checkrest(char **p_n, char *rest)
{
	char	*str;

	*p_n = ft_strchr2(rest, '\n');
	if ((p_n) != NULL)
	{
		str = ft_strsub(rest, 0, *p_n - rest);
		ft_strcpy(rest, ++(*p_n));
	}
	else
	{
		str = ft_strnew(ft_strlen2(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

static int	get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	char			*p_n;
	char			*tmp;
	int				rd;

	p_n = NULL;
	rd = 1;
	*line = checkrest(&p_n, rest);
	(rd = read(fd, buf, BUFF_SIZE));
	while (p_n == 0 && (rd != 0))
	{
		buf[rd] = '\0';
		p_n = ft_strchr(buf, '\n');
		if ((p_n) != NULL)
		{
			ft_strcpy(rest, ++p_n);
			ft_strclr(--p_n);
		}
		tmp = *line;
		(*line = ft_strjoin2(tmp, buf));
		if (!line || rd < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (ft_strlen2(*line) || ft_strlen2(rest) || rd);
}

int	get_next_line(const int fd, char **line)
{
	static t_arr	*list;
	t_arr			*tmp;
	int				ret;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = newlist(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = newlist(fd);
		tmp = tmp->next;
	}
	ret = get_line(fd, line, tmp->rest);
	return (ret);
}
