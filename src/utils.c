/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:23:40 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/01 16:52:53 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

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

void	check_dig(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
		isdigits(arg[i++]);
}

int	check_dig2(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		isdigits(arg[i]);
		i++;
	}
	return (i);
}

void	print_st(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d ", stack->stack[i]);
		i++;
	}
	ft_printf(" stack_%c ha %d elementi \n----------\n", stack->id, stack->size);
}

int	has_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
