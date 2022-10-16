/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aldo_ritmo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/16 18:31:22 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	simple_sort(t_stack *stack)
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

void	five_guys(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	min_max_val(stack_a);
	while (stack_a->stack[0] != stack_a->max)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	while (stack_a->stack[0] != stack_a->min)
		rotate_a(stack_a);
	push_to_b(stack_a, stack_b);
	simple_sort(stack_a);
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	rotate_a(stack_a);
}