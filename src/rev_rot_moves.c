/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:41:17 by blackronos        #+#    #+#             */
/*   Updated: 2022/11/01 17:37:45 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	reverse_rotate(t_stack *stack)
{
	int	*temp;
	int	i;

	i = 0;
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
	ft_printf("rra\n");
}

void	rev_rb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rev_ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_b);
	reverse_rotate(stack_a);
	ft_printf("rrr\n");
}
