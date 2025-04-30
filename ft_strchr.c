/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:03:44 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/27 13:37:02 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;
	unsigned char	a;

	a = c;
	i = 0;
	while (s[i] != a && s[i] != '\0')
		i++;
	if (s[i] == a)
		return ((char *)(s + i));
	return (0);
}
