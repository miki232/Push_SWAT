/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:39:25 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/30 16:49:45 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

int	check_stack(t_stack *stack)
{
	if (stack->size > 0)
		return (1);
	return (0);
}

// void	three_guys(t_stack *stack)
// {
// 	if (stack->stack[0] > stack->stack[1])
// 	{
// 		if (stack->stack[1] < stack->stack[2])
// 		{
// 			if (stack->stack[0] > stack->stack[2])
// 				rotate_a(stack);
// 			else
// 				swap_a(stack);
// 		}
// 		else
// 		{
// 			swap_a(stack);
// 			rev_ra(stack);
// 		}
// 	}
// 	else if (ordered_int(stack))
// 	{
// 		if (stack->stack[0] > stack->stack[2])
// 			rev_ra(stack);
// 		else
// 		{
// 			swap_a(stack);
// 			rotate_a(stack);
// 		}
// 	}
// }

void	three_guys(t_stack *stack)
{
	if (stack->stack[0] > stack->stack[1] && stack->stack[1] < stack->stack[2] \
		&& stack->stack[2] > stack->stack[0])
		swap_a(stack);
	else if (stack->stack[0] < stack->stack[1] && stack->stack[1] > stack->stack[2] \
				&& stack->stack[2] > stack->stack[0])
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack->stack[0] < stack->stack[1] && stack->stack[1] > stack->stack[2] \
			&& stack->stack[2] < stack->stack[0])
		rev_ra(stack);
	else if (stack->stack[0] > stack->stack[1] && stack->stack[1] > stack->stack[2] \
			&& stack->stack[2] < stack->stack[0])
	{
		rotate_a(stack);
		swap_a(stack);
	}
	else if (stack->stack[0] > stack->stack[1] && stack->stack[1] < stack->stack[2] \
			&& stack->stack[2] < stack->stack[0])
		rotate_a(stack);
}

void	moves_count_min_max(t_stack *stack, int num, int mn_mx)
{
	int	i;

	i = 0;
	while (stack->stack[i] != num)
	{
		i++;
	}
	if (!mn_mx)
		stack->i_min = i;
	else
		stack->i_max = i;
}

void	min_max_val(t_stack *s)
{
	int	i;

	s->max = 0;
	s->min = 0;
	i = 0;
	s->max = s->stack[0];
	s->min = s->max;
	while (i < s->size)
	{
		if (s->max < s->stack[i])
		{
			s->max = s->stack[i];
			s->i_max = i;
		}
		if (s->min > s->stack[i])
		{
			s->min = s->stack[i];
			s->i_min = i;
		}
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
	int	i;

	i = 0;
	while (i < 2)
	{
		min_max_val(stack_a);
		while (stack_a->stack[0] != stack_a->min)
		{
			moves_count_min_max(stack_a, stack_a->min, 0);
			if (stack_a->i_min > (stack_a->size / 2))
				rev_ra(stack_a);			
			else
				rotate_a(stack_a);
		}
		if (!ordered_int(stack_a))
		{
			break; ;
		}
		if (stack_a->stack[0] == stack_a->min)
		{
			push_to_b(stack_a, stack_b);
		}
		i++;
	}
	three_guys(stack_a);
	while (stack_b->size > 0)
	{
		push_to_a(stack_a, stack_b);
	}
}
