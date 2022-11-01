/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:47:21 by mtoia             #+#    #+#             */
/*   Updated: 2022/03/11 15:10:55 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= 'a' && argument <= 'z')
		|| (argument >= 'A' && argument <= 'Z'))
		return (1);
	else if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}
