/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:54:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/06/27 12:55:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>
int ft_error_handler_and_parser(t_stack **stk_a, int argc, char **argv)
{
	int i;
	char **checked_values;
	int checked_values_i;

	i = 1;
	if (argc < 2)
		return (1);
	while (i+1 <= argc)
	{
		if (!(checked_values = ft_split(argv[i], ' ')))
		{
			free(checked_values);
			exit(1);
		}
		checked_values_i = 0;
		while (checked_values[checked_values_i] != NULL)
		{
			if ((ft_number_checker(checked_values[checked_values_i]) == 1)
			|| ft_check_ll_doubles(stk_a, ft_long_long_atoi(checked_values[checked_values_i])) == 1)
			{
				free_list(*stk_a);
				clean_ptrs(checked_values);
				exit (1);
			}
			ft_lstadd_back(stk_a, ft_lstnew(ft_long_long_atoi(checked_values[checked_values_i])));
			checked_values_i++;
		}
		clean_ptrs(checked_values);
		i++;
	}
	return (0);
}


int		main(int argc, char **argv)
{
	t_stack *stk_a;
	stk_a = NULL;
	t_stack *stk_b;
	stk_b = NULL;

	if (ft_error_handler_and_parser(&stk_a, argc, argv) == 1)
	{
		printf("Error. yeahhh! error handling is working");
		//ft_lstclear(&stk_a, free);
		free_list(stk_a);
		return (1);
	}
	normalize_indexes(&stk_a);

	printf("Le stack originale e:\n");
	printf("\nStk a is \n");
	print_list(stk_a);
	printf("\nStk b is \n");
	print_list(stk_b);

	while (is_sorted(&stk_a) == 0)
	{
		srand(time(NULL));   // Initialization, should only be called once.
		int randomsort_switch = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
		//sort_small(&stk_a, &stk_b, randomsort_switch);
		sorting_algos(&stk_a, &stk_b, randomsort_switch);

		printf("\nStk a is \n");
		print_list(stk_a);
		printf("\nStk b is \n");
		print_list(stk_b);
	}

	if (is_sorted(&stk_a) == 1)
	{
		printf("\nStk a is \n");
		print_list(stk_a);
		printf("\nStk b is \n");
		print_list(stk_b);
		printf("Sorted!");
	}

	//free_list(stk_a);
	free_list2(&stk_a);
	free_list(stk_b);
	return (0);
}