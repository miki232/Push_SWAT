/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:50 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/11 15:25:01 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, int n)
{
	int				x;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	x = 0;
	while (x < n)
	{
		ptr[x++] = (unsigned char)c;
	}
	return (str);
}
