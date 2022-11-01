/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:06:56 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/22 11:53:58 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	udc;

	udc = c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == udc)
			return ((char *)s + i);
		i--;
	}
	return (0);
}
