/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:04:14 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/27 14:12:48 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_ndig(int n)
{
	int		ndig;

	ndig = 1;
	while (n / 10 != 0)
	{
		ndig++;
		n = n / 10;
	}
	if (n < 0)
		ndig++;
	return (ndig);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				ndig;
	unsigned int	nu;

	ndig = get_ndig(n);
	s = (char *)malloc((ndig + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[ndig] = '\0';
	nu = n;
	if (n < 0)
	{
		s[0] = '-';
		nu = n * -1;
	}
	ndig--;
	s[ndig] = (nu % 10) + '0';
	while (nu / 10 != 0)
	{
		ndig--;
		nu = nu / 10;
		s[ndig] = (nu % 10) + '0';
	}
	return (s);
}
