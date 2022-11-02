/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cn_cin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:55:19 by mardolin          #+#    #+#             */
/*   Updated: 2022/11/02 17:50:56 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push.h"

void	cn_one(int **chunk, t_stack *temp, t_stack *tmp_cn)
{
	if (tmp_cn->i < 45)
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	else if (tmp_cn->i > 44 && tmp_cn->i < 90)
	{
		if (tmp_cn->i == 45)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
	else if (tmp_cn->i > 89 && tmp_cn->i < 135)
	{
		if (tmp_cn->i == 90)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
}

void	cn_two(int **chunk, t_stack *temp, t_stack *tmp_cn)
{
	if (tmp_cn->i > 134 && tmp_cn->i < 180)
	{
		if (tmp_cn->i == 135)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
	else if (tmp_cn->i > 179 && tmp_cn->i < 225)
	{
		if (tmp_cn->i == 180)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
}

void	cn_three(int **chunk, t_stack *temp, t_stack *tmp_cn)
{
	if (tmp_cn->i > 224 && tmp_cn->i < 270)
	{
		if (tmp_cn->i == 225)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
	else if (tmp_cn->i > 269 && tmp_cn->i < 315)
	{
		if (tmp_cn->i == 270)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
}

void	cn_four(int **chunk, t_stack *temp, t_stack *tmp_cn)
{
	if (tmp_cn->i > 314 && tmp_cn->i < 360)
	{
		if (tmp_cn->i == 315)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
	else if (tmp_cn->i > 359 && tmp_cn->i < 405)
	{
		if (tmp_cn->i == 360)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
}

void	cn_five(int **chunk, t_stack *temp, t_stack *tmp_cn)
{
	if (tmp_cn->i > 404 && tmp_cn->i < 450)
	{
		if (tmp_cn->i == 405)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
	else if (tmp_cn->i > 449 && tmp_cn->i < 495)
	{
		if (tmp_cn->i == 450)
		{
			tmp_cn->j = 44;
			tmp_cn->c--;
		}
		chunk[tmp_cn->c][tmp_cn->j] = temp->stack[tmp_cn->i];
	}
	tmp_cn->i++;
	tmp_cn->j--;
}
