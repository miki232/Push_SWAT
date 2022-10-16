/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:23:40 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/16 11:27:28 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	value;

	value = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	value *= sign;
	if (value < -2147483648 || value > 2147483647)
		return (-1);
	return ((int)value);
}