/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:14:28 by crirodr2          #+#    #+#             */
/*   Updated: 2025/04/30 18:23:05 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_parsing.h"
#include "ft_printf_to_str.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_putchars_fd(int c, int n, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, &c, 1);
		i++;
	}
}

static void	put_0_padding(char **cont_str, int padding, t_convspec cspec)
{
	if (ft_strchr("di", cspec.type) && !ft_isdigit(*cont_str[0]))
	{
		ft_putchar_fd((*cont_str)[0], 1);
		(*cont_str)++;
	}
	else if (ft_strchr("xX", cspec.type)
		&& (ft_strchr(*cont_str, 'x') || ft_strchr(*cont_str, 'X')))
	{
		ft_putchar_fd((*cont_str)[0], 1);
		ft_putchar_fd((*cont_str)[1], 1);
		(*cont_str) += 2;
	}
	ft_putchars_fd('0', padding, 1);
}

static int	print_res(char *cont_str, t_convspec cspec)
{
	int	cont_len;
	int	padding;

	if (cspec.type == 'c')
		cont_len = 1;
	else
		cont_len = ft_strlen(cont_str);
	padding = 0;
	if (cspec.width > cont_len)
		padding = cspec.width - cont_len;
	if (cspec.flags[1] == '0' && ft_strchr("diuxX", cspec.type)
		&& cspec.prec == -2)
		put_0_padding(&cont_str, padding, cspec);
	else if (cspec.flags[1] != '-')
		ft_putchars_fd(' ', padding, 1);
	ft_putstr_fd(cont_str, 1);
	if (cspec.type == 'c' && cont_str[0] == '\0')
		ft_putchar_fd(cont_str[0], 1);
	if (cspec.flags[1] == '-')
		ft_putchars_fd(' ', padding, 1);
	return (cont_len + padding);
}

static int	conversion_printer(t_convspec cs, int *pchrs)
{
	char	*str;
	char	*printstr;

	str = NULL;
	if (cs.fill)
		str = content_to_str(cs);
	if (!str)
	{
		*pchrs = -1;
		return (1);
	}
	printstr = str;
	if ((ft_strchr("di", cs.type) && !cs.flags[2] && str[0] != '-')
		|| cs.type == 'u')
		printstr = str + 1;
	else if (ft_strchr("di", cs.type) && cs.flags[2] && str[0] != '-')
		str[0] = cs.flags[2];
	if (ft_strchr("xX", cs.type) && (!cs.flags[0] || *(int *)(cs.fill) == 0))
		printstr = str + 2;
	else if (cs.type == 'p' && *(unsigned long *)(cs.fill) == 0)
		printstr = "(nil)";
	*pchrs += print_res(printstr, cs);
	free(str);
	free(cs.fill);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_convspec	cspec;
	int			printed_chars;

	if (!format)
		return (-1);
	va_start(args, format);
	printed_chars = 0;
	while (*format != '\0')
	{
		format++;
		if (*(format - 1) != '%')
		{
			ft_putchar_fd(*(format - 1), 1);
			printed_chars++;
			continue ;
		}
		cspec = conversion_parser((char **)&(format), args, &printed_chars);
		if (cspec.type == '%')
			continue ;
		if (conversion_printer(cspec, &printed_chars))
			break ;
	}
	va_end(args);
	return (printed_chars);
}
