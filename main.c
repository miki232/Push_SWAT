/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/14 19:11:07 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int ft_ordered(int *array)
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

int ft_equals(int *array)
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

int *loader_int(char **argv, int argc)
{
    int i;
    int *array;

    i = 1;
    array = malloc(sizeof(int) * argc - 1);
    while (argv[i])
    {
      array[i - 1] = ft_atoi(argv[i]);
      i++;
    }
    return (array);
}

void ft_isdigit(char **array)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (array[j++])
    {
        while (array[j][i])
        {
            if (array[j][i + 1] > 47 && array[j][i + 1] < 58)
                i++;
            else
            {
                printf("ERppr\n");
                exit(0);
            }
            printf("%c\n", array[j][i]);
        }
    }
}

int	main(int argc, char **argv)
{
    (void)argc;
    int *array;

    ft_isdigit(argv);
	array = loader_int(argv, argc);
	while (*array)
    {
      printf("%d\n", *array);
      array++;
    }
    // printf("%d\n", array[0]);
    // printf("%d\n", array[1]);
}