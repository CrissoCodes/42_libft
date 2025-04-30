/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:47:42 by crirodr2          #+#    #+#             */
/*   Updated: 2025/04/30 15:35:34 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_parsing.h"
#include <stdarg.h>

static unsigned int	get_ndig(unsigned long n, int base, int prec)
{
	unsigned long	ndig;

	ndig = 0;
	while (n != 0)
	{
		ndig++;
		n = n / base;
	}
	if (prec == -2)
		prec = 1;
	if ((int) ndig < prec)
		ndig = prec;
	return (ndig);
}

static char	*ft_itosgna(long n, int prec)
{
	char			*s;
	int				ndig;
	unsigned long	nu;

	nu = n;
	if (n < 0)
		nu = n * -1;
	ndig = get_ndig(nu, 10, prec);
	s = (char *)ft_calloc(ndig + 1 + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	else
		s[0] = '+';
	while (nu != 0)
	{
		s[ndig--] = (nu % 10) + '0';
		nu = nu / 10;
	}
	while (ndig > 0)
		s[ndig--] = '0';
	return (s);
}

static char	*ft_itox(unsigned long n, int upper, int prec)
{
	char			*hex;
	char			*s;
	unsigned long	ndig;

	if (upper)
		hex = "0123456789ABCDEFX";
	else
		hex = "0123456789abcdefx";
	ndig = get_ndig(n, 16, prec);
	s = (char *)ft_calloc(ndig + 1 + 2, sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = hex[16];
	while (ndig > 0)
	{
		s[ndig - 1 + 2] = hex[n % 16];
		n = n / 16;
		ndig--;
	}
	return (s);
}

static char	*ft_stos(t_convspec cs)
{
	char	*str;

	if (*(char **)(cs.fill))
		str = ft_substr(*(char **)(cs.fill), 0, cs.prec);
	else if (cs.prec > 6 || cs.prec == -2)
		str = ft_strdup("(null)");
	else
		str = ft_strdup("");
	return (str);
}

char	*content_to_str(t_convspec cs)
{
	char	*str;

	str = NULL;
	if (cs.type == 'c')
	{
		str = (char *)ft_calloc(2, sizeof(char));
		str[0] = (char)(*(int *)(cs.fill));
	}
	else if (cs.type == 's')
		str = ft_stos(cs);
	else if (cs.type == 'i' || cs.type == 'd')
		str = ft_itosgna(*((int *)cs.fill), cs.prec);
	else if (cs.type == 'u')
		str = ft_itosgna(*((unsigned int *)cs.fill), cs.prec);
	else if (cs.type == 'x' || cs.type == 'X')
		str = ft_itox(*((unsigned int *)cs.fill), cs.type == 'X', cs.prec);
	else if (cs.type == 'p')
		str = ft_itox(*((unsigned long *)cs.fill), 0, cs.prec);
	return (str);
}
