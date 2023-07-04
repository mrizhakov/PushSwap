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
	printf("\nAfter doing normalize_local_indexes Stk a is \n");
	printf("\nStk a is \n");
	print_list(temp);
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

void sort_5_element_list(t_stack **stk_a, t_stack **stk_b, t_stack **sorted_lst )
{
	t_stack	*temp1;
	temp1 = *stk_a;
	t_stack	*temp2;
	temp2 = *stk_b;

	while (temp1 != NULL)
	{
		if (temp1->index == 0)
		{
			pb_push(&temp1,&temp2);
			break ;
		}
		ra_rb_rotate(&temp1, 'a');
//		temp1 = temp1->next;
	}
	printf("\nAfter finding and pushing smallest element to B \n");

	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);
	while (temp1 != NULL)
	{
		if (temp1->index == 1)
		{
			pb_push(&temp1,&temp2);
			break ;
		}
		ra_rb_rotate(&temp1, 'a');
//		temp1 = temp1->next;
	}
	printf("\nAfter finding and pushing next smallest element to B \n");
	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);
	printf("\nSort3 on stack A \n");
	//normalize_local_indexes(&temp1);


	sort_3_element_list(&temp1);
	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);

	pa_push(&temp2,&temp1);
	pa_push(&temp2,&temp1);

	//temp1 = *stk_a;
	printf("\nPushing 2 elements from stack B to A \n");

	printf("\nStk a is \n");
	print_list(temp1);
	printf("\nStk b is \n");
	print_list(temp2);

//	exit (1);

//
//	while (temp1->next != NULL)
//	{
//		if (temp1->index == 1)
//			break ;
//		temp1 = temp1->next;
//	}
//	print_list(temp1);
//
//	printf("Node content is %i\n", temp1->content);
//
//	while (temp1->index != 1)
//		temp1 = temp1->next;


//	pb_push(&temp1,&temp2);
//
//	sort_3_element_list(&temp1);
//
//	pa_push(stk_b,stk_a);
//	pa_push(stk_b,stk_a);

//	if (is_sorted(stk_b) == 1)
//		sa_sb_swap(stk_b, 'b');


//	if (stk_b[0]->index  stk_b[0]->index && stk_b[0]->index > stk_b[0]->index)
//		rra_rotate(stk_a);
//	if (stk_a[0]->index < stk_b[0]->index &&  stk_a[4]->index > stk_b[0]->index)
//		rra_rotate(stk_a);

//		if (temp[0].index == 1 &&  temp[2].index == 0 && temp[4].index == 2)
//			sa_sb_swap(stk_a, 'a');


//	printf("Stk a is \n");
//	print_list(*stk_a);
//	printf("Stk b is \n");
//
//	print_list(*stk_b);
//	exit (1);
//	pa_push(stk_b,stk_a);
//	printf("Stk a is \n");
//	print_list(*stk_a);
//	printf("Stk b is \n");
//
//	print_list(*stk_b);
//
//	ra_rb_rotate(stk_a, 'a');
//	printf("Stk a is \n");
//	print_list(*stk_a);
//	printf("Stk b is \n");
//
//	print_list(*stk_b);
//
//	pa_push(stk_b,stk_a);
//	printf("Stk a is \n");
//	print_list(*stk_a);
//	printf("Stk b is \n");
//	print_list(*stk_b);
//
//	ra_rb_rotate(stk_a, 'a');
//	printf("Stk a is \n");
//	print_list(*stk_a);
//	printf("Stk b is \n");
//
//	print_list(*stk_b);



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

void sort_small(t_stack **lst, t_stack **stk_b, t_stack **sorted_list, int randomvalue)
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

//
//		sa_sb_swap(lst, 'a');
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
		sort_5_element_list(lst, stk_b, sorted_list);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);
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
			printf("\nIs sorted says that stack is not sorted, stack is : \n");
			print_list(temp1);
			return (0);
		}
		temp1 = temp1->next;
	}
	printf("\nIs sorted says that stack is sorted, stack is : \n");
	print_list(temp1);
	return (1);
}
