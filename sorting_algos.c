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

void sort_3_element_list(t_stack **stk_a)
{
	t_stack	*temp;
	temp = *stk_a;

	normalize_local_indexes(&temp);


	if (temp->local_index == 0)
	{
		sa_sb_swap(stk_a, 'a');
		ra_rb_rotate(stk_a, 'a');
		return ;
	}
	if (temp->local_index == 1)
	{
		temp = temp->next;
		if (temp->local_index == 0)
			sa_sb_swap(stk_a, 'a');
		if (temp->local_index == 2)
			rra_rotate(stk_a);
		return ;
	}
	if (temp->local_index == 2)
	{
		temp = temp->next;
		if (temp->local_index == 0)
			ra_rb_rotate(stk_a, 'a');
		if (temp->local_index == 1)
		{
			sa_sb_swap(stk_a, 'a');
			rra_rotate(stk_a);
		}
		return ;
	}


//	if (temp[0].index == 1 &&  temp[2].index == 0 && temp[4].index == 2)
//		sa_sb_swap(stk_a, 'a');
//	if (temp[0].index == 2 &&  temp[2].index == 1 && temp[4].index == 0)
//	{
//		sa_sb_swap(stk_a, 'a');
//		rra_rotate(stk_a);
//	}
//	if (temp[0].index == 2 &&  temp[2].index == 0 && temp[4].index == 1)
//		ra_rb_rotate(stk_a, 'a');
//	if (temp[0].index == 0 &&  temp[2].index == 2 && temp[4].index == 1)
//	{
//		sa_sb_swap(stk_a, 'a');
//		ra_rb_rotate(stk_a, 'a');
//	}
//	if (temp[0].index == 1 &&  temp[2].index == 2 && temp[4].index == 0)
//		rra_rotate(stk_a);
//
//	printf("LST[0].content is %i, LST[0].index is %i\n", temp[0].content, temp[0].index);
//	printf("LST[1].content is %i, LST[1].index is %i\n", temp[1].content, temp[1].index);
//	printf("LST[2].content is %i, LST[2].index is %i\n", temp[2].content, temp[2].index);
//	printf("LST[3].content is %i, LST[3].index is %i\n", temp[3].content, temp[3].index);
//	printf("LST[4].content is %i, LST[4].index is %i\n", temp[4].content, temp[4].index);
//	printf("LST[5].content is %i, LST[5].index is %i\n", temp[5].content, temp[5].index);
//	printf("LST[6].content is %i, LST[6].index is %i\n", temp[6].content, temp[6].index);
//	printf("LST[7].content is %i, LST[7].index is %i\n", temp[7].content, temp[7].index);
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
			break;
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
	normalize_local_indexes(&temp1);


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

	exit (1);


	while (temp1->next != NULL)
	{
		if (temp1->index == 1)
			break ;
		temp1 = temp1->next;
	}
	print_list(temp1);

	printf("Node content is %i\n", temp1->content);
//
//	while (temp1->index != 1)
//		temp1 = temp1->next;


	pb_push(&temp1,&temp2);

	sort_3_element_list(&temp1);

	pa_push(stk_b,stk_a);
	pa_push(stk_b,stk_a);

//	if (is_sorted(stk_b) == 1)
//		sa_sb_swap(stk_b, 'b');


//	if (stk_b[0]->index  stk_b[0]->index && stk_b[0]->index > stk_b[0]->index)
//		rra_rotate(stk_a);
//	if (stk_a[0]->index < stk_b[0]->index &&  stk_a[4]->index > stk_b[0]->index)
//		rra_rotate(stk_a);

//		if (temp[0].index == 1 &&  temp[2].index == 0 && temp[4].index == 2)
//			sa_sb_swap(stk_a, 'a');


	printf("Stk a is \n");
	print_list(*stk_a);
	printf("Stk b is \n");

	print_list(*stk_b);
	exit (1);
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



//
//void is_sorted(t_stack **lst)
//{
//	t_stack	*temp;
//	temp = *lst;
//	int lst_size;
//
//	lst_size = ft_lstsize(temp);
//
//
//	if (temp == NULL || temp->next == NULL)
//		return ;
//	if (lst_size == 3)
//	{
//		printf("List is 3 elements long, lets get to work\n");
//	}
//
//
//
//}
//
//
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

//t_stack     *ft_lstnew(int content);
//void        ft_lstadd_back(t_stack **lst, t_stack *new);




//
//t_stack* copy_list(t_stack* head)
//{
//	if (head == NULL)
//		return NULL; // Return NULL for an empty list
//
//	t_stack* new_head = NULL; // Head of the new list
//	t_stack* prev = NULL; // Previous node in the new list
//
//	// Iterate over the original list
//	while (head != NULL)
//	{
//		// Create a new node
//		t_stack* new_node = (t_stack*)malloc(sizeof(t_stack));
//		if (new_node == NULL)
//		{
//			// Error handling for memory allocation failure
//			// Free the memory allocated so far and return NULL
//			while (new_head != NULL)
//			{
//				t_stack* temp = new_head;
//				new_head = new_head->next;
//				free(temp);
//			}
//			return NULL;
//		}
//
//		// Copy the content and index from the original node
//		new_node->content = head->content;
//		new_node->index = head->index;
//		new_node->next = NULL;
//
//		// Update the new list
//		if (prev == NULL)
//		{
//			new_head = new_node;
//		}
//		else
//		{
//			prev->next = new_node;
//		}
//		prev = new_node;
//		//free_list(new_node);
//
//		head = head->next;
//	}
//	return new_head;
//}

int is_sorted(t_stack **lst)
{
	t_stack *temp1;
	t_stack *temp2;

	t_stack *sorted_list;

	temp1 = *lst;
	temp2 = sorted_list;
	temp2 = copy_list(temp1);
	bubble_sort(&temp2);

	if (ft_lstsize(temp1) != ft_lstsize(temp2))
		return (0);

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->content != temp2->content)
		{
//			printf("List isnt sorted\n");

			return (0);
		}
//		printf("Lst node content is:%d\n", temp1->content);
//		printf("Sorted list node content is:%d\n", temp1->content);

		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return (1);
}

//void copy_linked_list(t_stack **lst, t_stack **copy_lst)
//{
//	t_stack *temp1;
//	t_stack *temp2;
//
//	temp1 = *lst;
//	temp2 = *copy_lst;
//
//	while (lst != NULL)
//	{
//		temp2->content = temp2->content;
//		temp1 = temp1->next;
//	}
//}

