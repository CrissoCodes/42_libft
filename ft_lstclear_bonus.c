/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:15:26 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/29 19:59:07 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (!(*lst))
		return ;
	next_node = (**lst).next;
	ft_lstdelone(*lst, del);
	while (next_node)
	{
		*lst = next_node;
		next_node = (**lst).next;
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}
