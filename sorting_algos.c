/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/06/27 12:54:51 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2_element_list(t_stack **lst, int flag)
{
	sa_sb_swap(lst, flag);
}

void sort_3_element_list(t_stack **stk_a) {
	t_stack *temp;
	temp = *stk_a;
	normalize_local_indexes(&temp);

	if (temp->local_index == 0) {
		sa_sb_swap(stk_a, 'a');
		ra_rb_rotate(stk_a, 'a');
		return;
	}
	if (temp->local_index == 1) {
		temp = temp->next;
		if (temp->local_index == 0) {
			sa_sb_swap(stk_a, 'a');
			return;
		}
		if (temp->local_index == 2) {
			rra_rotate(stk_a);
			return;
		}
	}
	if (temp->local_index == 2) {
		temp = temp->next;
		if (temp->local_index == 0) {
			ra_rb_rotate(stk_a, 'a');
			return;
		}
		if (temp->local_index == 1)
			sa_sb_swap(stk_a, 'a');
		rra_rotate(stk_a);
	}
}

void sort_5_element_list(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *temp1;
	temp1 = *stk_a;
	t_stack *temp2;
	temp2 = *stk_b;

	while (temp1 != NULL) {
		if (temp1->index == 0) {
			pb_push(&temp1, &temp2);
			break;
		}
		ra_rb_rotate(&temp1, 'a');
//		temp1 = temp1->next;
	}
	printf("\nAfter finding and pushing smallest element to B \n");

	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);
	while (temp1 != NULL) {
		if (temp1->index == 1) {
			pb_push(&temp1, &temp2);
			break;
		}
		ra_rb_rotate(&temp1, 'a');
//		temp1 = temp1->next;
	}
	printf("\nAfter two pushes to B \n");

	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);

//	printf("\nAfter finding and pushing next smallest element to B \n");
//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);
//	printf("\nSort3 on stack A \n");
	//normalize_local_indexes(&temp1);
	if (is_sorted(&temp1) == 0)
		sort_3_element_list(&temp1);

	printf("\nAfter is_sorted and sort3 \n");

	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);


//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);

	pa_push(&temp2, &temp1);
	pa_push(&temp2, &temp1);
	printf("\nAfter two pushes back to A \n");

	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);

	*stk_a = temp1;
	*stk_b = temp2;
}

int find_median(t_stack **lst)
{
	int median;
	int lst_size;
	t_stack *temp;

	temp = *lst;
	median = 0;
	lst_size = ft_lstsize(temp);
	printf("LSTSIZe is %d", lst_size);
	while (temp != NULL)
	{
		median = median + temp->index;
		temp = temp->next;
	}
	return (median / lst_size);
}

void push_smallest_to_b(t_stack **stk_a, t_stack **stk_b)
{
	printf("Push smallest to b!");
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;
	int operations;

	temp_a = *stk_a;
	temp_b = *stk_b;
	position = 0;
	normalize_local_indexes(&temp_a);
	lst_size = ft_lstsize(temp_a);
	operations = 0;
	while (temp_a->local_index != 0)
	{
		position++;
		temp_a = temp_a->next;
	}
	temp_a = *stk_a;

	if (position > lst_size / 2)
	{
		while (temp_a->local_index != 0)
		{
			rra_rotate(&temp_a);
			operations++;
		}

	}
	if (position <= lst_size / 2)
	{
		while (temp_a->local_index != 0)
		{
			ra_rb_rotate(&temp_a, 'a');
			operations++;

		}
	}
	pb_push(&temp_a, &temp_b);
	printf("\nAfter pushing smallest node, resuls are  \n");
	printf("\nNumber of operations %i \n", operations);


	printf("\nStk a is \n");
	print_list(temp_a);
	printf("\nStk b is \n");
	print_list(temp_b);

	*stk_a = temp_a;
	*stk_b = temp_b;
}

void push_smallest_to_a(t_stack **stk_a, t_stack **stk_b)
{
	printf("Push smallest to b!");
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;
	int operations;

	temp_a = *stk_a;
	temp_b = *stk_b;
	position = 0;
	normalize_local_indexes(&temp_b);
	lst_size = ft_lstsize(temp_b);
	operations = 0;
	while (temp_b->local_index != 0)
	{
		position++;
		temp_b = temp_b->next;
	}
	temp_b = *stk_b;

	if (position > lst_size / 2)
	{
		while (temp_b->local_index != 0)
		{
			rra_rotate(&temp_b);
			operations++;
		}

	}
	if (position <= lst_size / 2)
	{
		while (temp_b->local_index != 0)
		{
			ra_rb_rotate(&temp_b, 'a');
			operations++;

		}
	}
	pa_push(&temp_b, &temp_a);
	printf("\nAfter pushing smallest node, resuls are  \n");
	printf("\nNumber of operations %i \n", operations);


	printf("\nStk a is \n");
	print_list(temp_a);
	printf("\nStk b is \n");
	print_list(temp_b);

	*stk_a = temp_a;
	*stk_b = temp_b;
}

void sort_10(t_stack **stk_a, t_stack **stk_b)
{
	printf("Sort 10!");
	t_stack *temp_a;
	t_stack *temp_b;
	int median;
	int operations;
	int lst_size;
	temp_a = *stk_a;
	temp_b = *stk_b;

	lst_size = ft_lstsize(temp_a);
	while (lst_size != 3)
	{
		push_smallest_to_b(&temp_a, &temp_b);
		lst_size--;
	}
	sort_3_element_list(&temp_a);
	lst_size = ft_lstsize(temp_b);
	while (lst_size != 0)
	{
		pa_push(&temp_b, &temp_a);
		lst_size--;
	}

	printf("\nPush smallest to Stk B result is \n");

	printf("\nStk a is \n");
	print_list(temp_a);
	printf("\nStk b is \n");
	print_list(temp_b);
	*stk_a = temp_a;
	*stk_b = temp_b;

//	exit(1);

}



void sort_big(t_stack **stk_a, t_stack **stk_b, int chunks)
{
    printf("Sort 100!");
    t_stack *temp_a;
    t_stack *temp_b;
    int median;
    int operations;
    int lst_size;
    temp_a = *stk_a;
    temp_b = *stk_b;

    lst_size = ft_lstsize(temp_a);
    int chunk_size = lst_size / chunks;
    int current_chunk_size;

    while (lst_size != 3)
    {
        current_chunk_size = chunk_size;
        while (chunk_size != 0 & lst_size != 3)
        {
            push_smallest_to_b(&temp_a, &temp_b);
            current_chunk_size--;
            lst_size--;
        }
    }
    sort_3_element_list(&temp_a);
    lst_size = ft_lstsize(temp_b);
    while (lst_size != 0)
    {
        pa_push(&temp_b, &temp_a);
        lst_size--;
    }

    printf("\nPush smallest to Stk B result is \n");

    printf("\nStk a is \n");
    print_list(temp_a);
    printf("\nStk b is \n");
    print_list(temp_b);
    *stk_a = temp_a;
    *stk_b = temp_b;

}



void random_sort1(t_stack **lst)
{
	t_stack	*temp;
	temp = *lst;

	sa_sb_swap(lst, 'a');
}
void random_sort2(t_stack **lst)
{
	t_stack	*temp;
	temp = *lst;

	ra_rb_rotate(lst, 'a');
}

void sorting_algos(t_stack **lst, t_stack **stk_b, int randomvalue)
{
	t_stack	*temp;
	temp = *lst;
	int lst_size;

	lst_size = ft_lstsize(temp);


	if (temp == NULL || temp->next == NULL)
		return ;
	if (lst_size == 2)
	{
		sort_2_element_list(lst, 'a');
	}
	if (lst_size == 3)
	{
		sort_3_element_list(lst);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);

	}
	if (lst_size == 5)
	{
		sort_5_element_list(lst, stk_b);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);
	}

	if (lst_size > 5 && lst_size < 10)
	{
		sort_10(lst, stk_b);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);
	}

	if (lst_size > 10 && lst_size <= 100)
	{
		sort_big(lst, stk_b, lst_size / 4);
	}

	if (lst_size == 100)
	{
		sort_big(lst, stk_b, 25);
	}

	if (lst_size > 100 && lst_size <= 500)
	{
		sort_big(lst, stk_b, 62);
	}
	if (lst_size == 500)
	{
		sort_big(lst, stk_b, 71);
	}
}



t_stack* copy_list(t_stack* head)
{
	if (head == NULL)
		return NULL; // Return NULL for an empty list

	t_stack* new_head = NULL; // Head of the new list
	while (head != NULL)
	{
		ft_lstadd_back(&new_head, (ft_lstnew(head->content)));
		head = head->next;
	}
	return new_head;
}


int is_sorted(t_stack **lst)
{
	t_stack *temp1;
	temp1 = *lst;

	while (temp1->next != NULL)
	{
		if (temp1->content > temp1->next->content)
		{
			return (0);
		}
		temp1 = temp1->next;
	}
	return (1);
}
