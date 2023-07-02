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

void sort_3_element_list(t_stack **lst)
{
	t_stack	*temp;
	temp = *lst;

	ra_rb_rotate(lst, 'a');
	//sa_sb_swap(lst, 'a');

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

void sort_small(t_stack **lst, int randomvalue)
{
	t_stack	*temp;
	temp = *lst;
	int lst_size;

	lst_size = ft_lstsize(temp);


	if (temp == NULL || temp->next == NULL)
		return ;
	if (lst_size == 2)
	{
			sa_sb_swap(lst, 'a');
	}
	if (lst_size >= 3)
	{
		if (randomvalue > 1073741823)
			random_sort1(lst);
		if (randomvalue < 1073741823)
			random_sort2(lst);
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


int is_sorted(t_stack **lst, t_stack **sorted_list)
{
	t_stack *temp1;
	t_stack *temp2;

	temp1 = *lst;
	temp2 = *sorted_list;
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

t_stack* copy_list(t_stack* head)
{
	if (head == NULL)
		return NULL; // Return NULL for an empty list

	t_stack* new_head = NULL; // Head of the new list
	t_stack* prev = NULL; // Previous node in the new list

	// Iterate over the original list
	while (head != NULL) {
		// Create a new node
		t_stack* new_node = (t_stack*)malloc(sizeof(t_stack));
		if (new_node == NULL) {
			// Error handling for memory allocation failure
			// Free the memory allocated so far and return NULL
			while (new_head != NULL) {
				t_stack* temp = new_head;
				new_head = new_head->next;
				free(temp);
			}
			return NULL;
		}

		// Copy the content and index from the original node
		new_node->content = head->content;
		new_node->index = head->index;
		new_node->next = NULL;

		// Update the new list
		if (prev == NULL) {
			new_head = new_node;
		} else {
			prev->next = new_node;
		}
		prev = new_node;

		head = head->next;
	}

	return new_head;
}
