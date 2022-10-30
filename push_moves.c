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

#include "push.h"

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
