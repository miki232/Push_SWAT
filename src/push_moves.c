/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:39:12 by blackronos        #+#    #+#             */
/*   Updated: 2022/10/30 13:57:55 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	push_to(t_stack *dest, t_stack *src)
{
	dest->i = 0;
	dest->temp = malloc(sizeof(int) * dest->size);
	if (src == NULL)
		return (0);
	while (dest->i < dest->size)
	{
		dest->temp[dest->i] = dest->stack[dest->i];
		dest->i++;
	}
	dest->stack[0] = src->stack[0];
	dest->i = 0;
	while (dest->i <= dest->size)
	{
		dest->stack[dest->i + 1] = dest->temp[dest->i];
		dest->i++;
	}
	dest->i = 0;
	while (dest->i < src->size)
	{
		src->stack[dest->i] = src->stack[dest->i + 1];
		dest->i++;
	}
	free(dest->temp);
	return (0);
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 1)
		return ;
	push_to(stack_a, stack_b);
	stack_a->size += 1;
	stack_b->size -= 1;
	printf("pa\n");
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 1)
		return ;
	push_to(stack_b, stack_a);
	stack_a->size -= 1;
	stack_b->size += 1;
	printf("pb\n");
}

void	pushing(t_stack *stack_b)
{
	if (stack_b->i_max > (stack_b->size / 2))
		rev_rb(stack_b);
	else
		rotate_b(stack_b);
}

void	endmmove(t_stack *stack_a, t_stack *stack_b, t_stack *temp, int **cn)
{
	while (stack_a->size > (5))
	{
		find_n_set_a(stack_a, cn, stack_b->j);
		min_max_val(stack_b);
		if (stack_b->size < 1)
			push_to_b(stack_a, stack_b);
		else
			mmove_b(stack_a, stack_b, temp);
		chunck_index_increment(stack_b);
	}
	if (stack_a->size == 5)
		five_guys(stack_a, stack_b);
	min_max_val(stack_b);
	while (stack_b->stack[0] != stack_b->max)
	{
		rev_rb(stack_b);
	}
	move_ghelper(stack_a, stack_b);
}
