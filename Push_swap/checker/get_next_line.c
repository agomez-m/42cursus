/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:19:35 by agomez-m          #+#    #+#             */
/*   Updated: 2023/11/29 11:21:57 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	polish_list(tc_list **list)
{
	tc_list	*last_node;
	tc_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(tc_list));
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

char	*get_line(tc_list *list)
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

void	append(tc_list **list, char *buf)
{
	tc_list	*new_node;
	tc_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc (sizeof(tc_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node -> next = new_node;
	new_node -> str_buf = buf;
	new_node -> next = NULL;
}

void	create_list(tc_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_new_line(*list))
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
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static tc_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	polish_list (&list);
	return (next_line);
}
/*
void leaks()
{
	system("leaks -q a.out");
}

#include <stdio.h>
int	main(void)
{
	atexit(leaks);
	int		fd;
	char	*line;
	int		lines;
	lines = 1;
	fd = open ("text.txt", O_RDONLY);
	if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}
*/