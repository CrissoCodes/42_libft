/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:55:48 by crirodr2          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:59 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"
#include <stdio.h>

int	gnl_get_linelst(int fd, t_list **line_parts)
{
	char	*buff_read;
	ssize_t	tmp;

	buff_read = NULL;
	tmp = BUFFER_SIZE;
	while (gnl_find_char_in_set('\n', buff_read) == -1 && tmp == BUFFER_SIZE)
	{
		buff_read = (char *) malloc(BUFFER_SIZE + 1);
		if (!buff_read)
		{
			gnl_strlist_clear(line_parts);
			return (-1);
		}
		tmp = 0;
		while (tmp <= BUFFER_SIZE)
			buff_read[tmp++] = '\0';
		tmp = read(fd, buff_read, BUFFER_SIZE);
		if (tmp < 0 || gnl_strlst_append(line_parts, buff_read) == -1)
		{
			free(buff_read);
			gnl_strlist_clear(line_parts);
			return (-1);
		}
	}
	return (0);
}

size_t	gnl_size_line(t_list *line_list, char *prefix)
{
	size_t	line_len;
	size_t	i;

	line_len = 1;
	while (line_list && line_list -> next)
	{
		line_list = line_list -> next;
		line_len += BUFFER_SIZE;
	}
	i = 0;
	while (line_list && (line_list->content)[i] != '\n'
		&& (line_list->content)[i] != '\0')
		i++;
	line_len += i;
	if (!prefix)
		return (line_len);
	i = 0;
	while (prefix[i] != '\n' && prefix[i] != '\0')
		i++;
	line_len += i;
	return (line_len);
}

size_t	gnl_add_line_prefix(char *line, char **prefix)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*prefix))
		return (i);
	while ((*prefix)[i] != '\0' && (i == 0 || (*prefix)[i - 1] != '\n'))
	{
		line[i] = (*prefix)[i];
		i++;
	}
	j = 0;
	while ((i + j > 0) && (*prefix)[i + j - 1] != '\0')
	{
		(*prefix)[j] = (*prefix)[i + j];
		j++;
	}
	if ((*prefix)[0] == '\0')
	{
		free(*prefix);
		*prefix = NULL;
	}
	return (i);
}

char	*gnl_join_line(t_list *line_list, char **prefix)
{
	char	*full_line;
	size_t	ind_l;
	size_t	ind_b;

	full_line = (char *) malloc((gnl_size_line(line_list, (*prefix)) + 1) * 1);
	if (!full_line)
		return (NULL);
	ind_l = gnl_add_line_prefix(full_line, prefix);
	while (line_list)
	{
		ind_b = 0;
		while ((line_list -> content)[ind_b] != '\0'
			&& (ind_b == 0 || (line_list -> content)[ind_b - 1] != '\n'))
		{
			full_line[ind_l++] = (line_list -> content)[ind_b++];
		}
		line_list = line_list -> next;
	}
	full_line[ind_l] = '\0';
	return (full_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	t_list		*line_parts;
	static char	*rest[FOPEN_MAX];

	if (fd >= FOPEN_MAX || fd < 0)
		return (NULL);
	line_parts = NULL;
	if (gnl_find_char_in_set('\n', rest[fd]) == -1)
	{
		if (gnl_get_linelst(fd, &line_parts) == -1 && rest[fd])
		{
			free(rest[fd]);
			rest[fd] = NULL;
		}
	}
	line = gnl_join_line(line_parts, &(rest[fd]));
	if (gnl_set_static_buffer(line_parts, &(rest[fd])) == -1
		|| (line && !line[0]))
	{
		if (line)
			free(line);
		line = NULL;
	}
	gnl_strlist_clear(&line_parts);
	return (line);
}
