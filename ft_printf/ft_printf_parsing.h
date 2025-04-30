/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:33:17 by crirodr2          #+#    #+#             */
/*   Updated: 2025/03/11 23:19:00 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSING_H
# define FT_PRINTF_PARSING_H
# include <stdarg.h>

typedef struct s_conversion_specification
{
	char	*flags;
	int		width;
	int		prec;
	char	type;
	void	*fill;
}	t_convspec;

t_convspec	conversion_parser(char **locus, va_list content, int *pchrs);

#endif
