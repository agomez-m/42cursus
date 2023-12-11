/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:15:35 by agomez-m          #+#    #+#             */
/*   Updated: 2023/10/02 13:27:39 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
	{
		free(buf);
		free(clean_node);
		return ;
	}
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc (str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	append(t_list **list, char *buf, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(list[fd]);
	new_node = malloc (sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		list[fd] = new_node;
	else
		last_node -> next = new_node;
	new_node -> str_buf = buf;
	new_node -> next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_new_line(list[fd]))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		append(list, buf, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[8192];
	char			*next_line;

	if (fd < 0 || fd > 8191 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line(list[fd]);
	polish_list (&list[fd]);
	return (next_line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line;
	int		lines;
	lines = 1;
	fd = open ("text.txt", O_RDONLY);
	fd1 = open ("text1.txt", O_RDONLY);
	fd2 = open ("text2.txt", O_RDONLY);
	
	while ((line = get_next_line(fd)))
		printf("%d->%s\n", lines++, line);
	while ((line = get_next_line(fd1)))
		printf("%d->%s\n", lines++, line);
	while ((line = get_next_line(fd2)))
		printf("%d->%s\n", lines++, line);
	line = get_next_line(fd);
	printf("%s", line);
	printf("%s", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s", line);
	printf("%s", get_next_line(fd1));
	printf("%s\n", get_next_line(fd2));
	printf("%s", line);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
		
	close(fd);
	return (0);
}
