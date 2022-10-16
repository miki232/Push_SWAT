/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:30:03 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/16 17:21:08 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		*do_swap(t_stack *stack)
{
	int	temp;
	int	i;

	temp = 0;
	i = 0;
	while (i < 2)
	{
		temp = stack->stack[i + 1];
		i++;
		stack->stack[i] = stack->stack[i - 1];
		stack->stack[i - 1] = temp;
		i++;
	} 
	return (0);
}

void	swap_a(t_stack *stack_a)
{
	do_swap(stack_a);
	printf("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	do_swap(stack_b);
	printf("sb\n");
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	do_swap(stack_a);
	do_swap(stack_b);
	printf("ss\n");
}

int		push_to(t_stack *dest, t_stack *src)
{
	int *temp;
	int i;
	
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

void	rotate(t_stack *stack)
{
	int temp;
	int i;
	
	i = 0;
	temp = stack->stack[0];
	while (i < stack->size)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[i - 1] = temp;
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}

void	reverse_rotate(t_stack *stack)
{
	int *temp;
	int i;
	
	i = 0;
	//temp = stack->stack[stack->size - 1];
	temp = malloc(sizeof(int) * stack->size);
	while (i < stack->size)
	{
		temp[i] = stack->stack[i];
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		stack->stack[i + 1] = temp[i];
		i++;
	}
	stack->stack[0] = temp[stack->size - 1];
	free(temp);
}

void	rev_ra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	printf("rra\n");
}

void	rev_rb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rev_ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_b);
	reverse_rotate(stack_a);
	printf("rrr\n");
}
