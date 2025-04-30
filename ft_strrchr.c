/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:47 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/27 13:40:15 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	i;
	unsigned char	a;
	char			*ptr;

	a = c;
	i = 0;
	ptr = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
		{
			ptr = (char *)(s + i);
		}
		i++;
	}
	if (a == '\0')
		ptr = (char *)(s + i);
	return (ptr);
}
