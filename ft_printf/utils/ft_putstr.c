/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:23:06 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/02 12:02:40 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pritn(char c)
{
	write (1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (str[count] != '\0')
	{
		pritn(str[count]);
		count++;
	}
	return (count);
}
