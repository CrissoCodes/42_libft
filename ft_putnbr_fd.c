/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:59:37 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/24 12:34:54 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	posit;

	if (n < 0)
	{
		write(fd, "-", 1);
		posit = n * -1;
	}
	else
	{
		posit = n;
	}
	c = (posit % 10) + '0';
	if ((posit / 10) > 0)
		ft_putnbr_fd((int)(posit / 10), fd);
	write(fd, &c, 1);
}
