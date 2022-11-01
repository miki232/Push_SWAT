/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:43:50 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/02 12:02:32 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
