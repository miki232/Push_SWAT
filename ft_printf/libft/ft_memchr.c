/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:19:10 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/21 14:29:52 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t num)
{
	size_t			x;
	unsigned char	*str;

	str = (unsigned char *)s;
	x = 0;
	while (x < num)
	{
		if (str[x] == (unsigned char)c)
			return (&str[x]);
		x++;
	}
	return (0);
}
