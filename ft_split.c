/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crirodr2 <crirodr2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:38:32 by crirodr2          #+#    #+#             */
/*   Updated: 2025/01/28 15:38:39 by crirodr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_count_c(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	clean_subcalloc(char ***arr, size_t ind, size_t len)
{
	size_t	tmp;

	(*arr)[ind] = (char *)ft_calloc(len + 1, sizeof(char));
	if ((*arr)[ind])
		return ;
	tmp = 0;
	while (tmp <= ind)
		free((*arr)[tmp++]);
	free(*arr);
	*arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	wcount;
	size_t	windex;
	size_t	wlen;

	wcount = word_count_c(s, c);
	arr = (char **)ft_calloc(wcount + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	arr[wcount] = NULL;
	windex = 0;
	while (windex < wcount)
	{
		while (*s == c)
			s++;
		wlen = 0;
		while (s[wlen] != c && s[wlen] != '\0')
			wlen++;
		clean_subcalloc(&arr, windex, wlen);
		if (!arr)
			return (NULL);
		ft_strlcpy(arr[windex++], s, wlen + 1);
		s = s + wlen;
	}
	return (arr);
}
