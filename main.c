/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/15 17:52:53 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int *loader_int(char **argv, int argc)
{
    int i;
    int *array;

    i = 1;
    array = malloc(sizeof(int) * (argc - 1));
    if (!array)
        return (0);
    while (i < argc)
    {
        array[i - 1] = ft_atoi(argv[i]);
        i++;
    } 
    return (array);
}

int	main(int argc, char **argv)
{
    int *array;
    int argc2;
    char    **arg; 

    argc2 = 0;
    if (ft_space(argv[1]))
    {
        arg = ft_split(argv[1], ' ');
        //printf("%s\n", arg[2]);
        argc2 = check_dig2(arg);
        array = loader_int(arg, argc2);
        ft_equals(array, argc2);
        ft_ordered(array, argc2);
    }
    else
    {
        check_dig(argv);
        array = loader_int(argv, argc);
	    ft_equals(array, argc);
        ft_ordered(array, argc);
    }
}