/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:07:33 by mtoia             #+#    #+#             */
/*   Updated: 2022/10/16 18:34:06 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int *loader_int(char **argv, t_stack *stack_a, int i, int c)
{

    stack_a->stack = malloc(sizeof(int) * (stack_a->size));
    if (!stack_a->stack)
        return (0);
    while (i < stack_a->size + c)
    {
        if (c)
            stack_a->stack[i - 1] = ft_atoi(argv[i]);
        else
            stack_a->stack[i] = ft_atoi(argv[i]);
        i++;
    }
    return (0);
}

void    print_st(t_stack *stack)
{
    int i;

    i = 0;
    // while (i < stack->size)
    // {
    //     printf("%d ", i);
    //     i++;
    // }
    // printf("index \n");
    i = 0;
    while (i < stack->size)
    {
        printf("%d ", stack->stack[i]);
        i++;
    }
    printf(" stack_%c ha %d elementi \n----------\n", stack->id, stack->size);
}

int	main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;
    char    **arg; 

    stack_a.size = 0;
    stack_b.size = 0;
    stack_a.id = 'a';
    stack_b.id = 'b';
    // stack_b.stack[0] = 4;
    stack_b.size = 0;
    if (argc < 2)
    {
        printf("ERROR\n");
        exit(0); 
    }
    if (ft_space(argv[1]))
    {
        arg = ft_split(argv[1], ' ');
        stack_a.size = check_dig2(arg);
        loader_int(arg, &stack_a, 0, 0);
        stack_b.stack = malloc(sizeof(int) * stack_a.size);
        ft_equals(&stack_a);
        ft_ordered(&stack_a);
        swap_a(&stack_a);
        // push_to_b(&stack_a, &stack_b);
        // print_st(&stack_a);
        // print_st(&stack_b);
        // push_to_a(&stack_a, &stack_b);
        print_st(&stack_a);
        // print_st(&stack_b);
        rev_ra(&stack_a);
        print_st(&stack_a);
        rotate_a(&stack_a);
        print_st(&stack_a);
    }
    else
    {
        check_dig(argv);
        stack_a.size = argc - 1;
        stack_b.stack = malloc(sizeof(int) * stack_a.size);
        loader_int(argv, &stack_a, 1, 1);
	    ft_equals(&stack_a);
        ft_ordered(&stack_a);
        simple_sort(&stack_a);
        // swap_a(&stack_a);
        // push_to_b(&stack_a, &stack_b);
        // push_to_b(&stack_a, &stack_b);
        // push_to_b(&stack_a, &stack_b);
        // ra_rb(&stack_a, &stack_b);
        // rev_ra_rb(&stack_a, &stack_b);
        // swap_a(&stack_a);
        // push_to_a(&stack_a, &stack_b);
        // push_to_a(&stack_a, &stack_b);
        // push_to_a(&stack_a, &stack_b);
        // min_val(&stack_a);
        five_guys(&stack_a, &stack_b);
        //print_st(&stack_a);
        print_st(&stack_a);
	    print_st(&stack_b);
    }
}