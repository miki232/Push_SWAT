/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:23:40 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/03 14:08:30 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	ft_atoi(const char *str)
{
	t_help	help_atoi;

	init_atoi(&help_atoi);
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			help_atoi.sign *= -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		help_atoi.value *= 10;
		help_atoi.value += *str - '0';
		str++;
	}
	help_atoi.value *= help_atoi.sign;
	if (help_atoi.value < -2147483648 || help_atoi.value > 2147483647)
	{
		write(2, "Error\n", 7);
		exit (0);
	}
	return ((int)help_atoi.value);
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
