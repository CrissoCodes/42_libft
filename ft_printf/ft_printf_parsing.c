/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:38:27 by crirodr2          #+#    #+#             */
/*   Updated: 2025/04/30 15:35:33 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_parsing.h"

static char	*get_flags(char **site_ptr)
{
	static char	flag_buff[3];

	ft_bzero(flag_buff, 3);
	while (**site_ptr != '\0' && ft_strchr("#-0+ ", **site_ptr))
	{
		if (**site_ptr == '#')
			flag_buff[0] = '#';
		else if (**site_ptr == '-')
			flag_buff[1] = '-';
		else if (**site_ptr == '0' && flag_buff[1] != '-')
			flag_buff[1] = '0';
		else if (**site_ptr == '+')
			flag_buff[2] = '+';
		else if (**site_ptr == ' ' && flag_buff[2] != '+')
			flag_buff[2] = ' ';
		(*site_ptr)++;
	}
	return (flag_buff);
}

static int	get_field_width(char **site_ptr)
{
	int	width;

	if (**site_ptr == '*')
	{
		(*site_ptr)++;
		return (-1);
	}
	width = 0;
	while (**site_ptr >= '0' && **site_ptr <= '9')
	{
		width = width * 10 + (**site_ptr - '0');
		(*site_ptr)++;
	}
	return (width);
}

static int	get_prec(char **site_ptr)
{
	int	prec;

	if (**site_ptr != '.')
		return (-2);
	(*site_ptr)++;
	if (**site_ptr == '*')
	{
		(*site_ptr)++;
		return (-1);
	}
	prec = 0;
	while (**site_ptr >= '0' && **site_ptr <= '9')
	{
		prec = prec * 10 + (**site_ptr - '0');
		(*site_ptr)++;
	}
	return (prec);
}

void	*get_content(va_list *content, t_convspec cs)
{
	void	*ptr;

	ptr = NULL;
	if (cs.type == 'c' || cs.type == 'i' || cs.type == 'd'
		|| cs.type == 'u' || cs.type == 'x' || cs.type == 'X')
	{
		ptr = ft_calloc(1, sizeof(int));
		if (cs.type == 'c' || cs.type == 'i' || cs.type == 'd')
			*((int *)ptr) = va_arg(*content, int);
		else
			*((unsigned int *)ptr) = va_arg(*content, unsigned int);
	}
	else if (cs.type == 'p')
	{
		ptr = ft_calloc(1, sizeof(unsigned long long));
		*((unsigned long *)ptr) = va_arg(*content, unsigned long);
	}
	else if (cs.type == 's')
	{
		ptr = ft_calloc(1, sizeof(char *));
		*((char **)ptr) = va_arg(*content, char *);
	}
	return (ptr);
}

t_convspec	conversion_parser(char **locus, va_list *content, int *pchrs)
{
	t_convspec	cspec;

	cspec.flags = get_flags(locus);
	cspec.width = get_field_width(locus);
	cspec.prec = get_prec(locus);
	cspec.type = **locus;
	(*locus)++;
	if (cspec.width == -1)
		cspec.width = (int) va_arg(*content, unsigned int);
	if (cspec.prec == -1)
		cspec.prec = (int) va_arg(*content, unsigned int);
	cspec.fill = get_content(content, cspec);
	if (cspec.type == '%')
	{
		ft_putchar_fd('%', 1);
		(*pchrs)++;
	}
	return (cspec);
}
