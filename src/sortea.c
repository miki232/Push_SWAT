/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortea.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:25:29 by mtoia             #+#    #+#             */
/*   Updated: 2022/11/02 17:47:46 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	sortea(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	tmp;

	init_tmp(&tmp);
	min_max_val(stack_a);
	secondmin(stack_a);
	while (tmp.i < stack_a->size)
	{
		tmp.e = 0;
		tmp.c = 0;
		min_max_val(stack_a);
		while (stack_a->stack[tmp.c] != stack_a->min)
			tmp.c++;
		secondmin(stack_a);
		while (stack_a->stack[tmp.e] != stack_a->min)
			tmp.e++;
		help(stack_a, &tmp);
		tmp.i++;
		secondmin(stack_a);
		push_to_b(stack_a, stack_b);
		tmp.k++;
		if (tmp.i >= stack_a->size)
			tmp.i = 0;
	}
	tmp.i = 0;
	help_end(stack_a, stack_b, &tmp);
}
