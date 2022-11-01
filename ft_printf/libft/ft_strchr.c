/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:02:21 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/23 10:19:44 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	temp;

	temp = c;
	while (*s != '\0')
	{
		if (*s == temp)
			return ((char *)s);
		s++;
	}
	if (*s == temp)
		return ((char *)s);
	return (0);
}
