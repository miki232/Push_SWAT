/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aldo_ritmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackronos <blackronos@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/17 10:53:22 by blackronos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	three_guys(t_stack *stack)
{
	if(stack->stack[0] > stack->stack[1] && stack->stack[1] < stack->stack[2] && stack->stack[2] > stack->stack[0])
		swap_a(stack);
	else if(stack->stack[0] < stack->stack[1] && stack->stack[1] > stack->stack[2] && stack->stack[2] > stack->stack[0])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if(stack->stack[0] < stack->stack[1] && stack->stack[1] > stack->stack[2] && stack->stack[2] < stack->stack[0])
		rev_ra(stack);
	else if(stack->stack[0] > stack->stack[1] && stack->stack[1] > stack->stack[2] && stack->stack[2] < stack->stack[0])
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if(stack->stack[0] > stack->stack[1] && stack->stack[1] < stack->stack[2] && stack->stack[2] < stack->stack[0])
		rotate_a(stack);
}

void	min_max_val(t_stack *stack)
{
	int	i;

	stack->max = 0;
	stack->min = 0;
	i = 0;
	stack->max = stack->stack[0];
	stack->min = stack->max;
	while (i < stack->size)
	{
		if (stack->max < stack->stack[i])
 			stack->max = stack->stack[i];
		if (stack->min > stack->stack[i])
 			stack->min = stack->stack[i];
		i++;	
	}
}

void	four_guys(t_stack *stack_a, t_stack *stack_b)
{
	min_max_val(stack_a);
	while (stack_a->stack[0] != stack_a->min)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	three_guys(stack_a);
	push_to_a(stack_a, stack_b);	
}

void	five_guys(t_stack *stack_a, t_stack *stack_b)
{
	min_max_val(stack_a);
	while (stack_a->stack[0] != stack_a->max)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	while (stack_a->stack[0] != stack_a->min)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	three_guys(stack_a);
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	rotate_a(stack_a);
}