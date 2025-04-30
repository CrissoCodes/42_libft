/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:11:05 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/28 14:55:43 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	little_len = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && i + little_len <= len)
	{
		if (!ft_strncmp(big + i, little, little_len))
		{
			return (((char *) big) + i);
		}
		i++;
	}
	if (little[0] == '\0')
		return ((char *) big);
	return (NULL);
}
