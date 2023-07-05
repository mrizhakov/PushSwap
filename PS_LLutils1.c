/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_LLutils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:14 by mrizakov          #+#    #+#             */
/*   Updated: 2023/06/27 12:54:56 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void swap_nodes(t_stack *node1, t_stack *node2) {
	int temp = node1->content;
	int temp2 = node1->index;

	node1->content = node2->content;
	node1->index = node2->index;

	node2->content = temp;
	node2->index = temp2;

}

void bubble_sort(t_stack **head) {
	if (*head == NULL || (*head)->next == NULL) {
		return; // List is empty or has only one node, no sorting needed
	}

	int swapped;

	swapped = 1;
	t_stack *prev = NULL;

	while (swapped) {
		swapped = 0;
		t_stack *temp = *head;

		while (temp->next != prev) {
			if (temp->content > temp->next->content) {
				swap_nodes(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		prev = temp;
	}
}
//function to assign normalized indexes
//currently only finds the min value of the list
//my version which works sorts only negative numbers

void normalize_indexes(t_stack **head)
{
	if (*head == NULL)
		return; // List is empty or has only one node, no sorting needed

	t_stack *temp;
	int y = 0;
	int lst_size;
	lst_size = ft_lstsize(*head);
	int *sorted_list = (int *)malloc(sizeof(int)* lst_size);
	while(y != lst_size)
	{
		temp = *head;
		sorted_list[y] = INT_MAX;
		while (temp != NULL)
		{
			if (y == 0)
			{
				if (temp->content <= sorted_list[y])
				{
					sorted_list[y] = temp->content;
					temp->index = y;
				}
			}
			if (y>0)
			{
				if ((temp->content <= sorted_list[y]) && (temp->content > sorted_list[y - 1])) {
					sorted_list[y] = temp->content;
					temp->index = y;
				}
			}
			temp = temp->next;
		}
		y++;
	}
	free (sorted_list);
}

void normalize_local_indexes(t_stack **head)
{
	if (*head == NULL)
		return; // List is empty or has only one node, no sorting needed

	t_stack *temp;
	int y = 0;
	int lst_size;
	lst_size = ft_lstsize(*head);
	int *sorted_list = malloc(sizeof(int)* lst_size);
	while(y != lst_size)
	{
		temp = *head;
		sorted_list[y] = INT_MAX;
		while (temp != NULL)
		{
			if (y == 0)
			{
				if (temp->content <= sorted_list[y])
				{
					sorted_list[y] = temp->content;
					temp->local_index = y;
				}
			}
			if (y>0)
			{
				if ((temp->content <= sorted_list[y]) && (temp->content > sorted_list[y - 1])) {
					sorted_list[y] = temp->content;
					temp->local_index = y;
				}
			}
			temp = temp->next;
		}
		y++;
	}
//	*head = temp;
	free (sorted_list);
}

//old version of normalize indexes which kind of works for first element only maybe also for the second one
/*
void normalize_indexes(t_stack **head)
{
	if (*head == NULL) {
		return; // List is empty or has only one node, no sorting needed
	}
	t_stack *temp = *head;
	int *min = (int *)malloc(sizeof(int)* 100);
	int i;
	int y = 1;


	i = 1;
	min[0] = INT_MIN;
	int lowest_previous;
	lowest_previous = 0;
	//min = &temp->content;
	//min[0] = temp->content;

	//temp->index = i;
	min[y] = temp->content;


	while (y != 6)
	{
		temp = *head;
		//min[y] = temp->content;

		while (temp->next != NULL) {
			if ((temp->next->content < min[y]) && (min[y] > min[y-1]) )
			{
				//temp->next->index = i;

					min[y] = temp->next->content;


			}
			temp = temp->next;
		}
		y++;
	}
	printf("Minimum value is : %d\n", min[0]);
	printf("Minimum value is : %d\n", min[1]);
	printf("Minimum value is : %d\n", min[3]);
	printf("Minimum value is : %d\n", min[4]);
	printf("Minimum value is : %d\n", min[5]);
	printf("Index is : %d\n", i);
}
**/

t_stack *swap_nodes_by_value(t_stack **head, int val1, int val2) {
	if (head == NULL || val1 == val2) {
		return *head;
	}

	t_stack *prev1 = NULL, *prev2 = NULL, *curr = *head;
	t_stack *node1 = NULL, *node2 = NULL, *tempNode = NULL;

	while (curr) {
		if (node1 && node2) {
			break;
		}
		if (curr->content == val1) {
			node1 = curr;
			prev1 = tempNode;
		}
		if (curr->content == val2) {
			node2 = curr;
			prev2 = tempNode;
		}
		tempNode = curr;
		curr = curr->next;
	}

	if (!node1 || !node2) {
		return *head;
	}

	if (prev1) {
		prev1->next = node2;
	} else {
		head = &node2;
	}

	if (prev2) {
		prev2->next = node1;
	} else {
		head = &node1;
	}

	tempNode = node1->next;
	node1->next = node2->next;
	node2->next = tempNode;

	return *head;
}

t_stack *swap_nodes_by_index(t_stack **head, int index1, int index2)
{
	if (head == NULL || index1 == index2) {
		return *head;
	}

	t_stack *prev1 = NULL, *prev2 = NULL, *curr = *head;
	t_stack *node1 = NULL, *node2 = NULL, *tempNode = NULL;
	int i = 0;

	// Traverse the list to find the nodes at index1 and index2
	while (curr) {
		if (i == index1) {
			node1 = curr;
			prev1 = tempNode;
		}
		if (i == index2) {
			node2 = curr;
			prev2 = tempNode;
		}
		tempNode = curr;
		curr = curr->next;
		i++;
	}

	// If either node1 or node2 is not found
	if (!node1 || !node2) {
		return *head;
	}

	// Update the links to swap the nodes
	if (prev1) {
		prev1->next = node2;
	} else {
		head = &node2;
	}

	if (prev2) {
		prev2->next = node1;
	} else {
		head = &node1;
	}

	tempNode = node1->next;
	node1->next = node2->next;
	node2->next = tempNode;

	return *head;
}