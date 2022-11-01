/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:55:27 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/17 23:36:09 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *desti, const void *source, size_t num)
{
	char			step;
	size_t			index;
	unsigned char	*dest;
	unsigned char	*src;

	if (desti == NULL && source == NULL)
		return (NULL);
	step = +1;
	dest = (unsigned char *)desti;
	src = (unsigned char *)source;
	if (desti > source)
	{
		step = -1;
		dest = (unsigned char *)(desti + num - 1);
		src = (unsigned char *)(source + num - 1);
	}
	index = 0;
	while (index < num)
	{
		*dest = *src;
		dest += step;
		src += step;
		index++;
	}
	return (desti);
}
