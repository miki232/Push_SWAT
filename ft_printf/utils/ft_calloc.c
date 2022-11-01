/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:23:34 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/02 12:02:23 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
