/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_cin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:36:10 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/31 16:58:19 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push.h"

int	check_frst(int **chunk, t_stack *temp)
{
	// temp->i = 0;
	//temp->j = 44;
	//printf("oksodkas\n");
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
	// temp->j = 44;
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
	// temp->j = 44;
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
	// temp->j = 44;
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
	// temp->j = 44;
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