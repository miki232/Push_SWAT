/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:25:42 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/04 20:27:18 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_word(const char *s, char c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	*ft_substrss(const char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	if ((int)start >= (int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if ((int)len > (int)ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j++] = s[i];
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		i;
	int		len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substrss(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}

int	ft_strcmp(char *strg1, char *strg2)
{
	while ((*strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2)
	{
		strg1++;
		strg2++;
	}
	if (*strg1 == *strg2)
		return (0);
	else
		return (*strg1 - *strg2);
}
