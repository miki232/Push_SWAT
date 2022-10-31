/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:28:32 by mtoia             #+#    #+#             */
/*   Updated: 2022/04/04 11:17:52 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t	x;

	if (dest == NULL && source == NULL)
		return (NULL);
	x = 0;
	while (x < num)
	{
		((unsigned char *)dest)[x] = ((unsigned char *)source)[x];
		x++;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	temp;
	int				ind;

	ind = 0;
	temp = c;
	if (!s)
		return (0);
	while (s[ind] != '\0')
	{
		if (s[ind] == temp)
			return ((char *)&s[ind]);
		ind++;
	}
	if (s[ind] == temp)
		return ((char *)&s[ind]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	ix;
	size_t	j;
	size_t	ls1;
	size_t	ls2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	ix = 0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * ls1 + ls2 + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, ls1);
	while (*s2)
	{
		str[ls1] = *s2;
		s2++;
		ls1++;
	}
	str[ls1] = 0;
	free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int need_free)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	if (ft_strlen(s) <= len)
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < (unsigned int) ft_strlen(s))
	{
		while (i < len && s[start] != '\0')
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	if (need_free)
		free(s);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = ((char *)malloc(sizeof(char) * ft_strlen(s1) + 1));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
