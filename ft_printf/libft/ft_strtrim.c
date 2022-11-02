/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:57:03 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/02 17:57:53 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trunk(char c, const char *set)
{
	unsigned int	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
			index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ix;
	int		limiter;
	int		insd;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	limiter = ft_strlen(s1);
	insd = 0;
	ix = 0;
	while (s1[ix] && trunk(s1[ix], set))
		ix++;
	while (limiter > ix && trunk(s1[limiter - 1], set))
		limiter--;
	str = (char *)malloc(sizeof(*s1) * (limiter - ix + 1));
	if (!str)
		return (0);
	while (ix < limiter)
	{
		str[insd] = s1[ix];
		insd++;
		ix++;
	}
	str[insd] = 0;
	return (str);
}
