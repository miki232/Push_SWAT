/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:45:50 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/30 15:00:00 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	moves_for_first(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->stack[i] != stack_a->hlf)
		i++;
	return (i);
}

int	moves_for_second(t_stack *stack_a)
{
	int	c;

	c = stack_a->size - 1;
	while (stack_a->stack[c] != stack_a->hls
		|| stack_a->stack[c] == stack_a->hls)
	{
		if (stack_a->stack[c] == stack_a->hls)
		{
			break ;
		}
		c--;
	}
	return (c);
}

int	mov_push(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	stack_a->sec = shiva(temp, stack_a, stack_b);
	while (stack_b->stack[0] != stack_a->sec)
	{
		moves_count_min_max(stack_b, stack_a->sec);
		if (stack_b->i_min > (stack_b->size / 2))
			rev_rb(stack_b);
		else
			rotate_b(stack_b);
	}
	push_to_b(stack_a, stack_b);
	return (1);
}

int	mov_stack_b(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	if (stack_b->size < 1)
		push_to_b(stack_a, stack_b);
	else if (stack_a->stack[0] < stack_b->min
		|| stack_a->stack[0] > stack_b->max)
	{
		while (stack_b->stack[0] != stack_b->max)
		{
			moves_count_min_max(stack_b, stack_b->max);
			if (stack_b->i_min > (stack_b->size / 2))
				rev_rb(stack_b);
			else
				rotate_b(stack_b);
		}
		push_to_b(stack_a, stack_b);
	}
	else
		mov_push(stack_a, stack_b, temp);
	return (1);
}

int	base_moves(t_stack *stack_a, t_stack *stack_b)
{
	if ((stack_a->size - stack_a->c) > stack_a->i)
	{
		while (stack_a->i > 0)
		{
			rotate_a(stack_a);
			stack_a->i--;
		}
	}
	else
	{
		while (stack_a->c < stack_a->size)
		{
			rev_ra(stack_a);
			stack_a->c++;
		}	
	}
	return (1);
}
