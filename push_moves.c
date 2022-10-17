/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackronos <blackronos@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:39:12 by blackronos        #+#    #+#             */
/*   Updated: 2022/10/17 11:40:40 by blackronos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		push_to(t_stack *dest, t_stack *src)
{
	int	*temp;
	int	i;
	
	temp = malloc(sizeof(int) * dest->size);
	i = 0;
	if (src == NULL)
		return (0);
	//printf("ok");
	while(i < dest->size)
	{
		temp[i] = dest->stack[i];
		//printf("%d\n", temp[i]);
		i++;
	}
	dest->stack[0] = src->stack[0];
	i = 0;
	while(i <= dest->size)
	{
		dest->stack[i + 1] = temp[i];
		//printf("%d %d\n", dest->stack[i], i);
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
	//printf("a=%d b=%d\n", stack_a->size, stack_b->size);
	printf("pa\n");
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 1)
		return ;
	push_to(stack_b, stack_a);
	stack_a->size -= 1;
	stack_b->size += 1;
	//printf("a=%d b=%d\n", stack_a->size, stack_b->size);
	printf("pb\n");
}
