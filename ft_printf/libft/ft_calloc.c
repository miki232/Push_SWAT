/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:23:34 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/18 00:23:29 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	ix;

	ix = count * size;
	ptr = (char *)malloc(ix);
	if (!ptr)
		return (0);
	ft_bzero(ptr, ix);
	return (ptr);
}
