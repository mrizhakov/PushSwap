/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_LLutils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:14 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 18:17:31 by mrizakov         ###   ########.fr       */
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

void	normalize_indexes(t_stack **head)
{
	t_stack	*tmp;
	int		y;
	int		lst_size;
	int		*lst;

	y = 0;
	lst_size = ft_lstsize(*head);
	lst = malloc(sizeof(int) * lst_size);
	while (y != lst_size)
	{
		tmp = *head;
		lst[y] = INT_MAX;
		while (tmp != NULL)
		{
			if ((y == 0 && tmp->content <= lst[y]) || (y > 0 
					&& tmp->content <= lst[y] && tmp->content > lst[y - 1]))
			{
				lst[y] = tmp->content;
				tmp->index = y;
			}
			tmp = tmp->next;
		}
		y++;
	}
	free (lst);
}

void	normalize_local_indexes(t_stack **head)
{
	t_stack	*tmp;
	int		y;
	int		lst_size;
	int		*lst;

	y = 0;
	lst_size = ft_lstsize(*head);
	lst = malloc(sizeof(int) * lst_size);
	while (y != lst_size)
	{
		tmp = *head;
		lst[y] = INT_MAX;
		while (tmp != NULL)
		{
			if ((y == 0 && tmp->content <= lst[y]) || (y > 0 
					&& tmp->content <= lst[y] && tmp->content > lst[y - 1]))
			{
				lst[y] = tmp->content;
				tmp->local_index = y;
			}
			tmp = tmp->next;
		}
		y++;
	}
	free (lst);
}
