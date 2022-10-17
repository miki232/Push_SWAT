/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:39:12 by blackronos        #+#    #+#             */
/*   Updated: 2022/10/17 15:22:11 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	push_to(t_stack *dest, t_stack *src)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * dest->size);
	i = 0;
	if (src == NULL)
		return (0);
	while (i < dest->size)
	{
		temp[i] = dest->stack[i];
		i++;
	}
	dest->stack[0] = src->stack[0];
	i = 0;
	while (i <= dest->size)
	{
		dest->stack[i + 1] = temp[i];
		i++;
	}
	i = 0;
	while (i < src->size)
	{
		src->stack[i] = src->stack[i + 1];
		i++;
	}
	free(temp);
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
