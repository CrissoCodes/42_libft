/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:24:58 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:17 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	tmp;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!new)
		return (NULL);
	tmp = 0;
	while (tmp < len1)
	{
		new[tmp] = s1[tmp];
		tmp++;
	}
	tmp = 0;
	while (tmp < len2)
	{
		new[len1 + tmp] = s2[tmp];
		tmp++;
	}
	new[len1 + len2] = '\0';
	return (new);
}
