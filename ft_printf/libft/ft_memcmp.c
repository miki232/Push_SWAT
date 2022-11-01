/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:45:05 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/17 23:36:43 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)ptr1;
	s2 = (unsigned char *)ptr2;
	if (num == 0)
		return (0);
	while ((*s1 == *s2) && num - 1 > 0)
	{
		s1++;
		s2++;
		num--;
	}
	return (*s1 - *s2);
}
