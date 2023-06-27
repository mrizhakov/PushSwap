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

int ft_error_handler_and_parser(t_stack **stk_a, int argc, char **argv)
{

	//this is a test
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
	int len;
	t_stack *stk_a;
	stk_a = NULL;
	t_stack *stk_b;
	stk_b = NULL;

	if (ft_error_handler_and_parser(&stk_a, argc, argv) == 1)
	{
		printf("yeahhh! error handling is working");
		return (1);
	}

	printf("Original stack is : \n");
	print_list(stk_a);
	len = ft_lstsize(stk_a);
	printf("\nStack length is %i: \n", len);
	stk_a = swap_nodes_by_value(&stk_a, 0, 1);
	printf("Swaping elements with content 0 and 1 places gives the following stack: \n");
	print_list(stk_a);
	stk_a = swap_nodes_by_index(&stk_a, 1, 0);
	printf("\nSwaping elements at indexes 1 and 2 places gives the following stack: \n");
	print_list(stk_a);
	bubble_sort(&stk_a);
	printf("\nSorted stack is: \n");
	print_list(stk_a);


	printf("\nSA - swap 0 and 1 in stack A\n");
	stk_a = sa_swap(&stk_a, 0, 1);
	print_list(stk_a);

	printf("\nPB - push to B top value from A\n");
//	stk_b = reassign_first_element(stk_a, stk_b);
	pb_push(&stk_a, &stk_b);
	printf("\nStack A is: \n");
	print_list(stk_a);
	printf("\nStack B is: \n");
	print_list(stk_b);

	free_list(stk_a);
	return (0);
}
