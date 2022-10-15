/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:31 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/15 17:51:34 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void ft_ordered(int *array, int argc)
{
    int i;
    int j;
    
    j = 1;
    i = 0;
    while (array[i] < array[j])
    {
        i++;
        j++;
        if ((i + 1) == (argc - 1))
            printf("Ordered");
    }
}

void ft_equals(int *array, int argc)
{
    int i;
    int j;
    
    i = 0;
    j = 1;
    while(i < argc)
    {
        while(j < argc - 1)
        {
            if (array[i] == array[j])
            {
                printf("equals\n");
                exit(0);
            }
            j++;
        }
        i++;
        j = 1 + i;
    }
}

int    isdigits(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if((arg[i] > 47 && arg[i] < 58) || arg[i] == 45 || arg[i] == 43)
            i++;
        else
        {
            printf("ERROR");
            exit(0);
        }
    }
    return(1);
}

int		ft_space(char *arg)
{
	int i;

	i = 0;
	while (arg[i] != '\0')
	{
		if(arg[i] == ' ')
			return(1);
		i++;
	}
	return (0);
}

void    check_dig(char **arg)
{
    int i;

    i = 1;
    while (arg[i])
        isdigits(arg[i++]);
}

int    check_dig2(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
        isdigits(arg[i++]);
	return (i);
}