/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 18:26:32 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_rotate(t_stack **lst, char flag)
{
	t_stack	*head;

	head = pop_head(lst);
	if (flag == 'a')
		ft_putstr_fd("ra\n", 1);
	if (flag == 'b')
		ft_putstr_fd("rb\n", 1);
	ft_lstadd_back(lst, head);
}

//void	rr_rotate(t_stack **lst1, t_stack **lst2, char flag)
//{
//	ra_rb_rotate(lst1, flag);
//	ra_rb_rotate(lst2, flag);
//	ft_putstr_fd("rr\n", 1);
//}

void	rra_rotate(t_stack **lst)
{
	t_stack	*tail;

	tail = pop_tail(lst);
	ft_putstr_fd("rra\n", 1);
	ft_lstadd_front(lst, tail);
}

void	rrb_rotate(t_stack **lst)
{
	t_stack	*tail;

	tail = pop_tail(lst);
	ft_putstr_fd("rrb\n", 1);
	ft_lstadd_front(lst, tail);
}

//void	rrr_rotate(t_stack **lst1, t_stack**lst2)
//{
//	t_stack *tail1 = pop_tail(lst1);
//	t_stack *tail2 = pop_tail(lst2);
//
//	ft_putstr_fd("rrr\n", 1);
//	ft_lstadd_front(lst1, tail1);
//	ft_lstadd_front(lst2, tail2);
//}