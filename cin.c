/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:58 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/30 16:54:12 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_frst(int **chunk, t_stack *temp)
{
	if (temp->i < 45)
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	else if (temp->i > 44 && temp->i < 90)
	{
		if (temp->i == 45)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 89 && temp->i < 135)
	{
		if (temp->i == 90)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	return (1);
}

int	check_sec(int **chunk, t_stack *temp)
{
	if (temp->i > 134 && temp->i < 180)
	{
		if (temp->i == 135)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 179 && temp->i < 225)
	{
		if (temp->i == 180)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	return (1);
}

int	check_thr(int **chunk, t_stack *temp)
{
	if (temp->i > 224 && temp->i < 270)
	{
		if (temp->i == 225)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
    else if (temp->i > 269 && temp->i < 315)
	{
		if (temp->i == 270)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	return (1);
}

int	check_frt(int **chunk, t_stack *temp)
{
	if (temp->i > 314 && temp->i < 360)
	{
		if(temp->i == 315)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
    else if (temp->i > 359 && temp->i < 405)
	{
		if(temp->i == 360)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	return (1);
}

int	check_fv(int **chunk, t_stack *temp)
{
	if (temp->i > 404 && temp->i < 450)
	{
		if (temp->i == 405)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	else if (temp->i > 449 && temp->i < 495)
	{
		if (temp->i == 450)
		{
			temp->j = 44;
			temp->c--;
		}
		chunk[temp->c][temp->j] = temp->stack[temp->i];
	}
	temp->i++;
	temp->j--;
	return (1);
}

int	check_chunk_cc(int **chunk, t_stack *temp)
{
	init_temp_c(temp);
	while (temp->i < 495)
	{
		check_frst(chunk, temp);
		check_sec(chunk, temp);
		check_thr(chunk, temp);
		check_frt(chunk, temp);
		check_fv(chunk, temp);
	}
	return (1);
}

int	**init_c(int **chunk, t_stack *stack_a, t_stack *temp)
{
	temp->id = 't';
	temp->stack = malloc(sizeof(int) * stack_a->size);
	temp->size = stack_a->size;
	while (stack_a->i < 11)
	{
		chunk[stack_a->i] = malloc(sizeof(int *) * 45);
		stack_a->i++;
	}
	checkss(stack_a, temp);
	check_chunk_cc(chunk, temp);
	return (chunk);
}

int size_c(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 45)
		stack_a->j++;
	if (stack_b->size == 90)
		stack_a->j++;
	if (stack_b->size == 135)
		stack_a->j++;
	if (stack_b->size == 180)
		stack_a->j++;
    if (stack_b->size == 225)
		stack_a->j++;
    if (stack_b->size == 270)
		stack_a->j++;
    if (stack_b->size == 315)
		stack_a->j++;
    if (stack_b->size == 360)
		stack_a->j++;
    if (stack_b->size == 405)
		stack_a->j++;
    if (stack_b->size == 450)
		stack_a->j++;
	return (1);
}

void	sortc(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	min_max_val(stack_a);
	temp->cn = malloc(sizeof(int **) * 11);
	temp->cn = init(temp->cn, stack_a, temp);
	while (stack_a->size > (5))
	{
		hold_first_num(stack_a, temp->cn, stack_a->j);
		hold_second_num(stack_a, temp->cn, stack_a->j);
		stack_a->i = moves_for_first(stack_a);
		stack_a->c = moves_for_second(stack_a);
		base_moves(stack_a, stack_b);
		min_max_val(stack_b);
		mov_stack_b(stack_a, stack_b, temp);
		size_c(stack_a, stack_b);
	}
	while (stack_b->stack[0] != stack_b->max)
	{
		rotate_b(stack_b);
		min_max_val(stack_b);
		while (stack_b->stack[0] == stack_b->max && stack_b->size > 0)
		{
			push_to_a(stack_a, stack_b);
			min_max_val(stack_b);
		}
	}
}
