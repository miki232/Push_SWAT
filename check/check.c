/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:31 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/05 14:42:08 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_ordered(t_stack *stack_a)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (stack_a->stack[i] < stack_a->stack[j])
	{
		i++;
		j++;
		if ((i + 1) == (stack_a->size))
		{
			return (1);
		}
	}
	return (0);
}

void	ft_equals(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack_a->size)
	{
		while (j < stack_a->size)
		{
			if (stack_a->stack[i] == stack_a->stack[j])
			{
				write(2, "Error\n", 7);
				exit(0);
			}
			j++;
		}
		i++;
		j = 1 + i;
	}
}

int	isdigits(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if ((arg[i] > 47 && arg[i] < 58) || arg[i] == 45 || arg[i] == 43)
			i++;
		else
		{
			write(2, "Error\n", 7);
			exit(0);
		}
	}
	return (1);
}

int	ft_space(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_move(t_stack *stack_a)
{
	if (ft_ordered(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
