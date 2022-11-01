/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:36:46 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/21 15:43:44 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	parcount(const char *str, char spec)
{
	int		y;

	y = 0;
	while (*str)
	{
		if (*str != spec)
		{
			y++;
			while (*str && *str != spec)
				str++;
		}
		else
			str++;
	}
	return (y);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**big;

	if (!s)
		return (NULL);
	i = 0;
	big = (char **)malloc((parcount(s, c) + 1) * sizeof(char *));
	if (!big)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s != c && *s && ++len)
				++s;
			big[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	big[i] = 0;
	return (big);
}
