/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:44:05 by mardolin          #+#    #+#             */
/*   Updated: 2022/11/02 17:54:20 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	free_stuff(t_stack *temp)
{
	free(temp->stack);
	freechunk(temp);
	free(temp->cn);
}

void	help_end(t_stack *stack_a, t_stack *stack_b, t_stack *tmp)
{
	while (tmp->i < stack_b->size)
	{
		min_max_val(stack_b);
		while (stack_b->stack[0] != stack_b->max)
		{
			moves_count_min_max(stack_b, stack_b->max);
			if (stack_b->i_min > (stack_b->size / 2))
				rev_rb(stack_b);
			else
				rotate_b(stack_b);
		}
		push_to_a(stack_a, stack_b);
		tmp->k++;
		tmp->i++;
		if (tmp->i >= stack_b->size)
			tmp->i = 0;
	}
}
