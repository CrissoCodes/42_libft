/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 23:05:39 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/27 19:56:13 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	tmp;

	if (ft_strlen(s) < start)
		tmp = 0;
	else if (len > ft_strlen(s) - start)
		tmp = ft_strlen(s) - start;
	else
		tmp = len;
	subs = ft_calloc(tmp + 1, sizeof(char));
	if (!subs)
		return (NULL);
	subs[tmp] = '\0';
	while (tmp > 0)
	{
		tmp--;
		subs[tmp] = s[tmp + start];
	}
	return (subs);
}
