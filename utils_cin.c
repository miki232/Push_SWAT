/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:38:33 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/31 17:03:01 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	moves_count_min_max_cin(t_stack *stack, int num)
{
	int	i;
	
	i = 0;
	while (stack->stack[i] != num)
	{
		i++;
	}
	stack->i_max = i;	
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

int	**init_cin(int **chunk, t_stack *stack_a, t_stack *temp)
{
	temp->id = 't';
	temp->stack = malloc(sizeof(int) * stack_a->size);
	temp->size = stack_a->size;
	temp->i = 0;
	while (temp->i < 11)
	{
		chunk[temp->i] = malloc(sizeof(int *) * 45);
		temp->i++;
	}
	temp->i = 0;
	checkss(stack_a, temp);
	check_chunk_cc(chunk, temp);
	printcn(cn, 0);
	printcn(cn, 1);
	printcn(cn, 2);
	printcn(cn, 3);
	printcn(cn, 4);
	printcn(cn, 5);
	printcn(cn, 6);
	printcn(cn, 7);
	printcn(cn, 8);
	printcn(cn, 9);
	printcn(cn, 10);
	return (chunk);
}

int	shiva_cin(t_stack *temp, t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int	c;

	c = stack_b->size - 1;
	i = 499;
	while (temp->stack[i] != stack_a->stack[0])
		i--;
	while (c >= 0)
	{
		if (stack_b->stack[c] == temp->stack[i - 1])
			return (stack_b->stack[c]);
		else if (c == 0)
		{
			c = stack_b->size;
			i--;
		}
		c--;
	}
	return (0);
}

int	chunk_index_increment(t_stack *stack_b)
{
	if (stack_b->size == 45)
		stack_b->j--;
	if (stack_b->size == 90)
		stack_b->j--;
	if (stack_b->size == 135)
		stack_b->j--;
	if (stack_b->size == 180)
		stack_b->j--;
    if (stack_b->size == 225)
		stack_b->j--;
    if (stack_b->size == 270)
		stack_b->j--;
    if (stack_b->size == 315)
		stack_b->j--;
    if (stack_b->size == 360)
		stack_b->j--;
    if (stack_b->size == 405)
		stack_b->j--;
    if (stack_b->size == 450)
		stack_b->j--;
	return (1);
}
