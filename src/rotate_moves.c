/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:40:18 by blackronos        #+#    #+#             */
/*   Updated: 2022/11/01 17:36:05 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

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
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
