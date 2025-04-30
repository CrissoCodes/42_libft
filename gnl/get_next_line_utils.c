/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:11:13 by crirodr2          #+#    #+#             */
/*   Updated: 2025/04/30 17:01:49 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

ssize_t	gnl_find_char_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set && set[i] != '\0')
	{
		if (c == set[i])
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strlst_append(t_list **lst, char *content)
{
	t_list	*last_node;
	t_list	*new;

	last_node = *lst;
	while (last_node && last_node -> next)
		last_node = last_node -> next;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (-1);
	new -> content = content;
	new -> next = NULL;
	if (last_node)
		last_node -> next = new;
	else
		*lst = new;
	return (0);
}

void	gnl_strlist_clear(t_list **lst)
{
	t_list	*next_node;

	if (!(*lst))
		return ;
	next_node = (**lst).next;
	while (next_node)
	{
		free((**lst).content);
		free(*lst);
		*lst = next_node;
		next_node = (**lst).next;
	}
	free((**lst).content);
	free(*lst);
	*lst = NULL;
}

int	gnl_set_static_buffer(t_list *lst, char **rest)
{
	t_list	*last_node;
	size_t	ind1;
	size_t	ind2;

	if (!lst)
		return (0);
	last_node = lst;
	while (last_node && last_node -> next)
		last_node = last_node -> next;
	ind1 = 0;
	while (((*last_node).content)[ind1] != '\n'
		&& ((*last_node).content)[ind1] != '\0')
		ind1++;
	if (!(*rest) && ((*last_node).content)[ind1] != '\0')
	{
		*rest = (char *) malloc(BUFFER_SIZE * sizeof(char));
		if (!(*rest))
			return (-1);
	}
	ind2 = 0;
	while (((*last_node).content)[ind1] != '\0')
		(*rest)[ind2++] = ((*last_node).content)[1 + ind1++];
	return (0);
}
