/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:38:58 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/27 13:39:37 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (i < n)
	{
		if (*((char *)(s1 + i)) != *((char *)(s2 + i)))
		{
			a = *((char *)(s1 + i));
			b = *((char *)(s2 + i));
			return (a - b);
		}
		i++;
	}
	return (0);
}
