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
	t_stack *stk_sorted;
	stk_sorted = NULL;


	if (ft_error_handler_and_parser(&stk_a, argc, argv) == 1)
	{
		printf("Error. yeahhh! error handling is working");
		return (1);
	}

//	copy_linked_list(&stk_a, &stk_sorted);
//
//
//	stk_sorted = stk_a;
	normalize_indexes(&stk_a);

//	stk_sorted = copy_list(stk_a);
//	bubble_sort(&stk_sorted);
//	normalize_indexes(&stk_sorted);


//	print_list(stk_sorted);
	print_list(stk_a);;
//	printf("LST[0][0]->index %i\n", stk_a[0].content);
//	printf("LST[0][1]->index %i\n", stk_a[1].content);
//	printf("LST[0][2]->index %i\n", stk_a[2].content);
//	printf("LST[0][2]->index %i\n", stk_a[3].content);
//	printf("LST[0][2]->index %i\n", stk_a[4].content);
//	printf("LST[0][2]->index %i\n", stk_a[5].content);
//	printf("LST[0][2]->index %i\n", stk_a[6].content);
//	printf("LST[0][2]->index %i\n", stk_a[7].content);
//	printf("LST[0][2]->index %i\n", stk_a[8].content);
//	printf("LST[0][2]->index %i\n", stk_a[9].content);





//	while (is_sorted(&stk_a, &stk_sorted) == 1)
//	{
//		printf("Sorted!");
//		return 0;
//	}


//	sort_small(&stk_a);

//	printf("Stk a is \n");
//	print_list(stk_a);
//	printf("Stk b is \n");
//	print_list(stk_b);
//	if (is_sorted(&stk_a) == 1)
//		printf("Sorted!");
//	exit (1);


	//intf("RAND_MAX is %i", RAND_MAX);
	while (is_sorted(&stk_a) != 1)
	{
		srand(time(NULL));   // Initialization, should only be called once.
		int randomsort_switch = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.

		sort_small(&stk_a, &stk_b, &stk_sorted, randomsort_switch);
//		printf("\nStack A is: \n");
//
//		print_list(stk_a);
		//printf("\nSorted stack is: \n");

//		print_list(stk_sorted);

	}
	printf("HELLO!");

	if (is_sorted(&stk_a) == 1)
	{
		printf("Stk a is \n");
		print_list(stk_a);
		printf("Stk b is \n");
		print_list(stk_b);
			printf("LST[0][0]->index %i\n", stk_a[0].content);
	printf("LST[0][1]->index %i\n", stk_a[1].content);
	printf("LST[0][2]->index %i\n", stk_a[2].content);
	printf("LST[0][2]->index %i\n", stk_a[3].content);
	printf("LST[0][2]->index %i\n", stk_a[4].content);
	printf("LST[0][2]->index %i\n", stk_a[5].content);
	printf("LST[0][2]->index %i\n", stk_a[6].content);
	printf("LST[0][2]->index %i\n", stk_a[7].content);
	printf("LST[0][2]->index %i\n", stk_a[8].content);
	printf("LST[0][2]->index %i\n", stk_a[9].content);


		printf("Sorted!");

	}

//	print_list_with_indexes(&stk_a);
//	//stk_sorted = bubble_sort(&stk_a);
//	//sort_small(&stk_a);
//
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\nSorted stack is : \n");
//	print_list(stk_sorted);

	free_list(stk_sorted);
	free_list(stk_a);
	free_list(stk_b);
	return (0);
}






//
//	bubble_sort(&stk_a);
//	printf("\nSorted stack A is: \n");
//	print_list(stk_a);
//	printf("\n");
//
//	printf("\n\nRR - rotate stack A and B - shift elements down by 1 (The first element becomes the last one.)\n");
//	rr_rotate(&stk_a, &stk_b, ' ');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//
//
//
//
//	printf("\n\nSS upgraded - swap first two elements of A and B\n");
//	ss_swap(&stk_a, &stk_b, ' ');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nSA upgraded - swap first two elements of A\n");
//	sa_sb_swap(&stk_a, 'a');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\n");
//
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//
//	printf("\n\nSS upgraded - swap first two elements of A and B\n");
//	ss_swap(&stk_a, &stk_b, ' ');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nPB - push to B top value from A\n");
//	pb_push(&stk_a, &stk_b);
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//
//
//
//
////	printf("Original stack is : \n");
////	print_list(stk_a);
////	printf("\n");
////	len = ft_lstsize(stk_a);
////	printf("\nStack length is %i: \n", len);
////	stk_a = swap_nodes_by_value(&stk_a, 0, 1);
////	printf("Swaping elements with content 0 and 1 places gives the following stack: \n");
////	print_list(stk_a);
////	stk_a = swap_nodes_by_index(&stk_a, 1, 0);
////	printf("\nSwaping elements at indexes 1 and 2 places gives the following stack: \n");
////	print_list(stk_a);
////	printf("\nSorted stack is: \n");
////	print_list(stk_a);
////
////
////	printf("\nSA - swap 0 and 1 in stack A\n");
////	stk_a = sa_swap(&stk_a, 0, 1);
////	print_list(stk_a);
////
////	printf("\nPB - push to B top value from A\n");
////	pb_push(&stk_a, &stk_b);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////
////
////	printf("\nStack A length is: %d \n", ft_lstsize(stk_a));
////
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////	printf("\n");
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nRA - rotate stack A - shift up elements by 1 (The first element becomes the last one.)\n");
////
////	ra_rotate(&stk_a);
////	printf("\nStack A is: \n");
////
////	print_list(stk_a);
////	printf("\n");
////
////	printf("\nRRA - reverse rotate stack A - shift elements down by 1 (The last element becomes the first one.)\n");
////	ra_rotate(&stk_a);
////	printf("Stack A is: \n\n");
////
////	print_list(stk_a);
//
//
//
//
//	printf("\n\nRB - rotate stack B - shift elements down by 1 (The first element becomes the last one.)\n");
//	ra_rb_rotate(&stk_b, 'b');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nRB - rotate stack B - shift elements down by 1 (The first element becomes the last one.)\n");
//	ra_rb_rotate(&stk_b, 'b');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nRA - rotate stack A - shift elements down by 1 (The first element becomes the last one.)\n");
//	ra_rb_rotate(&stk_a, 'a');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//	printf("\n\nRA - rotate stack A - shift elements down by 1 (The first element becomes the last one.)\n");
//	ra_rb_rotate(&stk_a, 'a');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
//
//	printf("\n\nRR - rotate stack A and B - shift elements down by 1 (The first element becomes the last one.)\n");
//	rr_rotate(&stk_a, &stk_b, ' ');
//	printf("\nStack A is: \n");
//	print_list(stk_a);
//	printf("\nStack B is: \n");
//	print_list(stk_b);
//	printf("\n");
//
////
////	printf("\n\nRRA - reverse rotate stack A - shift elements down by 1 (The last element becomes the first one.)\n");
////	rra_rotate(&stk_a);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////	printf("\n");
////
////
////	printf("\n\nRRA - reverse rotate stack A - shift elements down by 1 (The last element becomes the first one.)\n");
////	rra_rotate(&stk_a);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////	printf("\n");
////
////	printf("\n\nRRB - reverse rotate stack B - shift elements down by 1 (The last element becomes the first one.)\n");
////	rrb_rotate(&stk_b);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////	printf("\n");
////
////	printf("\n\nRRR - reverse rotate stack A and B - shift elements down by 1 (The last element becomes the first one.)\n");
////	rrr_rotate(&stk_a, &stk_b);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////	printf("\n");
////
////	printf("\n\nRRR - reverse rotate stack A and B - shift elements down by 1 (The last element becomes the first one.)\n");
////	rrr_rotate(&stk_a, &stk_b);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////	printf("\n");
////
////
////
////	printf("\n\nSA upgraded - swap first two elements of A\n");
////	sa_swap_upgraded(&stk_a);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\n");
//
//
//
//
//
////	printf("\nRRR - reverse rotate stack A and B - shift elements down by 1 (The last element becomes the first one.)\n");
////	rrr_rotate(&stk_a, &stk_b);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);
////
////	printf("\nRRR - reverse rotate stack A and B - shift elements down by 1 (The last element becomes the first one.)\n");
////	rrr_rotate(&stk_a, &stk_b);
////	printf("\nStack A is: \n");
////	print_list(stk_a);
////	printf("\nStack B is: \n");
////	print_list(stk_b);



