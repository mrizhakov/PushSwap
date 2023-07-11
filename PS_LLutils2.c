/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_LLutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 20:32:58 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_stack	*ft_lstlast(t_stack *lst)
//{
//	int		i;
//	t_stack	*temp;
//
//	i = 0;
//	temp = lst;
//	if (lst == NULL)
//		return (0);
//	while (temp->next != NULL)
//	{
//		i++;
//		temp = temp->next;
//	}
//	return (temp);
//}

//void	ft_lstdelone(t_stack *lst, void (*del)(void *))
//{
//	if (!del)
//		return ;
//	del((void *)(lst->content));
//	free(lst);
//}

//void	ft_lstclear(t_stack **lst, void (*del)(void *))
//{
//	t_stack	*temp;
//
//	if (!del)
//		return ;
//	while (lst && *lst)
//	{
//		temp = (*lst)->next;
//		ft_lstdelone(*lst, del);
//		*lst = temp;
//	}
//}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(*new_node));
	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = lst;
	if (lst == NULL)
		return (0);
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	if (temp->next == NULL)
		i++;
	return (i);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

// void free_list2(t_stack** head)
// {
// 	t_stack* current;
// 	current = *head;
// 	t_stack* next;

// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	*head = current;
// }

void	free_list(t_stack	*head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_check_ll_doubles(t_stack **lst, int new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->content == new)
		{
			ft_putstr_fd("Found a double! Try again", 1);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
