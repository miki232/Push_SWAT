/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/13 16:27:42 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

#include <stdio.h>
int ft_ordered(char *array)
{
    int i;
    int j;
    j = 0;
    i = -1;
    while (array[j])
        j++;
    while(array[j - 1] != array[i])
    {
        if (array[i] > array[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int ft_equals(char **array)
{
    int i;
    int j;
    i = -1;
    j = 0;
    while(array[++i])
    {
        j = i;
        while(array[++j])
        {
            if (array[i] == array[j])
                return (0);
        }
    }
    return (1);
}

int main()
{
    char* str = "12 36 6 5";
	char **ret;
	int i = 0;
	ret = ft_split(str, ' ');
	//printf("%s\n", ret[3]);
	printf("%d", ft_equals(ret));
}