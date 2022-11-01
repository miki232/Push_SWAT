/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:30:03 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/17 15:23:14 by mardolin         ###   ########.fr       */
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
	printf("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	do_swap(stack_b);
	printf("sb\n");
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	printf("ss\n");
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