/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:30:03 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/01 17:35:36 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	*do_swap(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	while (i < 2)
	{
		temp = stack->stack[i + 1];
		i++;
		stack->stack[i] = stack->stack[i - 1];
		stack->stack[i - 1] = temp;
		i++;
	}
	return (0);
}

void	swap_a(t_stack *stack_a)
{
	do_swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	do_swap(stack_b);
	ft_printf("sb\n");
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	ft_printf("ss\n");
}

int	ordered_int(t_stack *stack)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (stack->stack[i] < stack->stack[j])
	{
		i++;
		j++;
		if ((i + 1) == (stack->size))
		{
			return (0);
		}
	}
	return (1);
}
