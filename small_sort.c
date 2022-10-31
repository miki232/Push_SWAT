/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:39:25 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/31 15:22:28 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	three_guys(t_stack *s)
{
	if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2] \
		&& s->stack[2] > s->stack[0])
		swap_a(s);
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2] \
				&& s->stack[2] > s->stack[0])
	{
		swap_a(s);
		rotate_a(s);
	}
	else if (s->stack[0] < s->stack[1] && s->stack[1] > s->stack[2] \
			&& s->stack[2] < s->stack[0])
		rev_ra(s);
	else if (s->stack[0] > s->stack[1] && s->stack[1] > s->stack[2] \
			&& s->stack[2] < s->stack[0])
	{
		rotate_a(s);
		swap_a(s);
	}
	else if (s->stack[0] > s->stack[1] && s->stack[1] < s->stack[2] \
			&& s->stack[2] < s->stack[0])
		rotate_a(s);
}

void	moves_count_min_max(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->stack[i] != num)
	{
		i++;
	}
	stack->i_min = i;
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
			moves_count_min_max(stack_a, stack_a->min);
			if (stack_a->i_min > (stack_a->size / 2))
				rev_ra(stack_a);
			else
				rotate_a(stack_a);
		}
		if (!ordered_int(stack_a))
		{
			break ;
		}
		if (stack_a->stack[0] == stack_a->min)
		{
			push_to_b(stack_a, stack_b);
		}
		i++;
	}
	three_guys(stack_a);
}
