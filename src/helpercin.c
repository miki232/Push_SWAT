/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/31 14:14:10 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	moves_count_min_max_cin(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->stack[i] != num)
		i++;
	stack->i_max = i;
}

int	shiva_cin(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	c;

	c = stack_b->size - 1;
	i = 499;
	while (temp->stack[i] != stack_a->stack[0])
		i--;
	while (c >= 0)
	{
		if (stack_b->stack[c] == temp->stack[i - 1])
			return (stack_b->stack[c]);
		else if (c == 0)
		{
			c = stack_b->size;
			i--;
		}
		c--;
	}
	return (0);
}

void	chunck_index_increment(t_stack *stack_b)
{
	if (stack_b->size == 45)
		stack_b->j--;
	if (stack_b->size == 90)
		stack_b->j--;
	if (stack_b->size == 135)
		stack_b->j--;
	if (stack_b->size == 180)
		stack_b->j--;
	if (stack_b->size == 225)
		stack_b->j--;
	if (stack_b->size == 270)
		stack_b->j--;
	if (stack_b->size == 315)
		stack_b->j--;
	if (stack_b->size == 360)
		stack_b->j--;
	if (stack_b->size == 405)
		stack_b->j--;
	if (stack_b->size == 450)
		stack_b->j--;
}

void	move_ghelper(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->stack[0] == stack_b->max || stack_b->size > 0)
	{
		while (stack_b->stack[0] != stack_b->max)
		{
			rev_rb(stack_b);
		}	
		push_to_a(stack_a, stack_b);
		if (stack_b->size > 0)
			min_max_val(stack_b);
	}
}

void	mmove_b(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	if (stack_a->stack[0] < stack_b->min
		|| stack_a->stack[0] > stack_b->max)
	{
		while (stack_b->stack[0] != stack_b->max)
		{
			moves_count_min_max_cin(stack_b, stack_b->max);
			pushing(stack_b);
		}
		push_to_b(stack_a, stack_b);
	}
	else
	{
		stack_a->sec = shiva_cin(temp, stack_a, stack_b);
		while (stack_b->stack[0] != stack_a->sec)
		{
			moves_count_min_max_cin(stack_b, stack_a->sec);
			pushing(stack_b);
		}
		push_to_b(stack_a, stack_b);
	}
}
