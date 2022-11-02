/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:56:03 by mardolin          #+#    #+#             */
/*   Updated: 2022/11/02 17:54:52 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

int	init_tmp(t_stack *tmp)
{
	tmp->c = 0;
	tmp->i = 0;
	tmp->k = 0;
	tmp->e = 0;
	return (0);
}

int	init_tmp_cn(t_stack *tmp_cn)
{
	tmp_cn->c = 10;
	tmp_cn->i = 0;
	tmp_cn->j = 44;
	return (0);
}

int	**init_cin(int **chunk, t_stack *stack_a, t_stack *temp)
{
	t_stack	tmp_cn;

	init_tmp_cn(&tmp_cn);
	temp->id = 't';
	temp->stack = malloc(sizeof(int) * stack_a->size);
	temp->size = stack_a->size;
	while (tmp_cn.i < 11)
	{
		chunk[tmp_cn.i] = malloc(sizeof(int *) * 45);
		tmp_cn.i++;
	}
	checkss(stack_a, temp);
	tmp_cn.i = 0;
	while (tmp_cn.i < 495)
	{
		cn_one(chunk, temp, &tmp_cn);
		cn_two(chunk, temp, &tmp_cn);
		cn_three(chunk, temp, &tmp_cn);
		cn_four(chunk, temp, &tmp_cn);
		cn_five(chunk, temp, &tmp_cn);
	}
	return (chunk);
}

int	init_struct(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->id = 'a';
	stack_b->id = 'b';
	stack_a->sec = 0;
	stack_a->i = 0;
	stack_a->c = 0;
	stack_a->j = 0;
	return (0);
}

int	init_temp(t_stack *temp)
{
	temp->j = 19;
	temp->i = 0;
	temp->c = 4;
	return (0);
}
