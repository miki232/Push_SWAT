/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:29:00 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/18 00:36:40 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ix;
	size_t	ls1;
	size_t	ls2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	ix = 0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = malloc(ls1 + ls2 + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, ls1);
	while (*s2)
	{
		str[ls1] = *s2;
		s2++;
		ls1++;
	}
	str[ls1] = 0;
	return (str);
}
