/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sortea.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:47:55 by mardolin          #+#    #+#             */
/*   Updated: 2022/11/02 17:52:48 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	help_rev(t_stack *stack_a, t_stack *tmp)
{
	if (tmp->c > (stack_a->size / 2) && tmp->e > (stack_a->size / 2))
	{
		if (tmp->c > tmp->e)
		{
			while (tmp->c < stack_a->size)
			{
				rev_ra(stack_a);
				tmp->k++;
				tmp->c++;
			}
		}
		else if (tmp->e > tmp->c)
		{
			while (tmp->e < stack_a->size)
			{
				rev_ra(stack_a);
				tmp->k++;
				tmp->e++;
			}
		}
	}
}

void	help_rev_rot(t_stack *stack_a, t_stack *tmp)
{
	if (tmp->c > (stack_a->size / 2) && tmp->e < (stack_a->size / 2))
	{
		if (tmp->c > tmp->e)
		{
			while (tmp->c < stack_a->size)
			{
				rev_ra(stack_a);
				tmp->k++;
				tmp->c++;
			}
		}
		else if (tmp->e < tmp->c)
		{
			while (tmp->e > 0)
			{
				rotate_a(stack_a);
				tmp->k++;
				tmp->e--;
			}
		}
	}
}

void	help_rot(t_stack *stack_a, t_stack *tmp)
{
	if (tmp->c < (stack_a->size / 2) && tmp->e > (stack_a->size / 2))
	{
		if (tmp->c < tmp->e)
		{
			while (tmp->c > 0)
			{
				rotate_a(stack_a);
				tmp->k++;
				tmp->c--;
			}
		}
	}
}

void	help_rots(t_stack *stack_a, t_stack *tmp)
{
	if (tmp->e < (stack_a->size / 2) && tmp->c < (stack_a->size / 2))
	{
		if (tmp->c < tmp->e)
		{
			while (tmp->c > 0)
			{
				rotate_a(stack_a);
				tmp->k++;
				tmp->c--;
			}
		}
		else if (tmp->e < tmp->c)
		{
			while (tmp->e > 0)
			{
				rotate_a(stack_a);
				tmp->k++;
				tmp->e--;
			}
		}
	}
}

void	help(t_stack *stack_a, t_stack *tmp)
{
	help_rev(stack_a, tmp);
	help_rev_rot(stack_a, tmp);
	help_rot(stack_a, tmp);
	help_rots(stack_a, tmp);
}
