/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 18:25:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb_swap(t_stack **head, char flag)
{
	t_stack	*original_stack;
	t_stack	*original_stack2;
	t_stack	*first_element;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	original_stack = *head;
	original_stack = original_stack->next;
	original_stack2 = original_stack->next;
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

//void ss_swap(t_stack **head1, t_stack **head2, char flag)
//{
//	sa_sb_swap(head1, flag);
//	sa_sb_swap(head2, flag);
//	ft_putstr_fd("ss\n", 1);
//}

void	pa_push(t_stack **head_src, t_stack **head_dest)
{
	t_stack	*tmp;

	tmp = *head_src;
	if (*head_src == NULL)
		return ;
	ft_putstr_fd("pa\n", 1);
	*head_src = (*head_src)->next;
	tmp->next = *head_dest;
	*head_dest = tmp;
}

void	pb_push(t_stack	**head_src, t_stack	**head_dest)
{
	t_stack	*tmp;

	tmp = *head_src;
	if (*head_src == NULL)
		return ;
	ft_putstr_fd("pb\n", 1);
	*head_src = (*head_src)->next;
	tmp->next = *head_dest;
	*head_dest = tmp;
}

t_stack	*pop_head(t_stack	**lst)
{
	t_stack	*first_node;

	if (*lst == NULL)
		return (NULL);
	first_node = *lst;
	*lst = (*lst)->next;
	first_node->next = NULL;
	return (first_node);
}

t_stack	*pop_tail(t_stack	**lst)
{
	t_stack	*temp;
	t_stack	*last_node;

	temp = *lst;
	if (*lst == NULL)
		return (NULL);
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
