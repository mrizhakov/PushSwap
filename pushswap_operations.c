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

//old sa_swap - can use any indexes

/*
t_stack *sa_swap(t_stack **head, int index1, int index2)
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
	ft_putstr_fd("\nsa\n", 1);

	return *head;
}
*/


void sa_sb_swap(t_stack **head, char flag)
{
	t_stack *original_stack;
	t_stack *original_stack2;

	if ( *head == NULL || (*head)->next == NULL)
		return;
	// resetting head one element down
	original_stack = *head;
	original_stack = original_stack->next;
	// keeping track of the third element for later use
	original_stack2 = original_stack->next;
	//	taking the first element and connecting it downstream of the updated head
	t_stack *first_element;
	first_element = *head;
	original_stack->next = first_element;
	if ((*head)->next->next == NULL)
		original_stack->next->next = NULL;
	else
		original_stack->next->next = original_stack2;
	*head = original_stack;
	if (flag == 'a')
		ft_putstr_fd("sa\n", 1);
	if (flag == 'b')
		ft_putstr_fd("sb\n", 1);
}

void ss_swap(t_stack **head1, t_stack **head2, char flag)
{
	sa_sb_swap(head1, flag);
	sa_sb_swap(head2, flag);
	ft_putstr_fd("ss\n", 1);
}

void pa_push(t_stack **head_src, t_stack **head_dest)
{
	t_stack *tmp;

	tmp = *head_src; //copy the head of source to tmp
	if (*head_src == NULL)
		return ;
	ft_putstr_fd("pa\n", 1);
	*head_src = (*head_src)->next;  //point the head of source one element down
	tmp->next = *head_dest; //point the next of temp to destination
	*head_dest = tmp; //update the head of destination to start with tmp
}

void pb_push(t_stack **head_src, t_stack **head_dest)
{
	t_stack *tmp;

	tmp = *head_src; //copy the head of source to tmp

	if (*head_src == NULL)
		return ;

	ft_putstr_fd("pb\n", 1);

	*head_src = (*head_src)->next;  //point the head of source one element down
	tmp->next = *head_dest; //point the next of temp to destination
	*head_dest = tmp; //update the head of destination to start with tmp
}

t_stack *pop_head(t_stack **lst)
{
	t_stack	*first_node;

	if (*lst == NULL)
		return NULL;
	first_node = *lst;
	*lst = (*lst)->next;
	first_node->next = NULL;
	return (first_node);
}

t_stack *pop_tail(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*last_node;
	temp = *lst;

	if (*lst == NULL)
		return NULL;
	if (temp->next == NULL)
	{
		last_node = temp;
		temp = temp->next;
		*lst = temp;
		return (last_node);
	}
	while (temp->next->next != NULL)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	last_node->next = NULL;
	return (last_node);
}
//The first element becomes the last one.

void	ra_rb_rotate(t_stack **lst, char flag)
{
	t_stack *head = pop_head(lst);

	if (flag == 'a')
		ft_putstr_fd("ra\n", 1);
	if (flag == 'b')
		ft_putstr_fd("rb\n", 1);

	ft_lstadd_back(lst, head);
}

void	rr_rotate(t_stack **lst1, t_stack **lst2, char flag)
{
	ra_rb_rotate(lst1, flag);
	ra_rb_rotate(lst2, flag);
	ft_putstr_fd("rr\n", 1);
}

void	rra_rotate(t_stack **lst)
{
	t_stack *tail = pop_tail(lst);
	ft_putstr_fd("rra\n", 1);
	ft_lstadd_front(lst, tail);
}

void	rrb_rotate(t_stack **lst)
{
	t_stack *tail = pop_tail(lst);
	ft_putstr_fd("rrb\n", 1);
	ft_lstadd_front(lst, tail);
}

void	rrr_rotate(t_stack **lst1, t_stack**lst2)
{
	t_stack *tail1 = pop_tail(lst1);
	t_stack *tail2 = pop_tail(lst2);

	ft_putstr_fd("rrr\n", 1);
	ft_lstadd_front(lst1, tail1);
	ft_lstadd_front(lst2, tail2);
}