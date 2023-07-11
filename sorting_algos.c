/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 21:13:14 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_element_list(t_stack **lst, int flag)
{
	sa_sb_swap(lst, flag);
}

void	sort_3_element_list(t_stack **stk_a)
{
	sort_3_element_list1(stk_a);
	sort_3_element_list2(stk_a);
}

void	sort_3_element_list1(t_stack **stk_a)
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
		{
			sa_sb_swap(stk_a, 'a');
			return ;
		}
		if (temp->local_index == 2)
		{
			rra_rotate(stk_a);
			return ;
		}
	}
}

void	sort_3_element_list2(t_stack **stk_a)
{
	t_stack	*temp;

	temp = *stk_a;
	normalize_local_indexes(&temp);
	if (temp->local_index == 2)
	{
		temp = temp->next;
		if (temp->local_index == 0)
		{
			ra_rb_rotate(stk_a, 'a');
			return ;
		}
		if (temp->local_index == 1)
			sa_sb_swap(stk_a, 'a');
		rra_rotate(stk_a);
	}
}

//void	sort_3_element_list(t_stack **stk_a)
//{
//	t_stack	*temp;
//
//	temp = *stk_a;
//	normalize_local_indexes(&temp);
//	if (temp->local_index == 0)
//	{
//		sa_sb_swap(stk_a, 'a');
//		ra_rb_rotate(stk_a, 'a');
//		return ;
//	}
//	if (temp->local_index == 1)
//	{
//		temp = temp->next;
//		if (temp->local_index == 0)
//		{
//			sa_sb_swap(stk_a, 'a');
//			return ;
//		}
//		if (temp->local_index == 2)
//		{
//			rra_rotate(stk_a);
//			return ;
//		}
//	}
//	if (temp->local_index == 2)
//	{
//		temp = temp->next;
//		if (temp->local_index == 0)
//		{
//			ra_rb_rotate(stk_a, 'a');
//			return ;
//		}
//		if (temp->local_index == 1)
//			sa_sb_swap(stk_a, 'a');
//		rra_rotate(stk_a);
//	}
//}

void	sort_5_element_list(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	pb_two_smallest_elements(stk_a, stk_b);
	temp1 = *stk_a;
	temp2 = *stk_b;
	if (is_sorted(&temp1) == 0)
		sort_3_element_list(&temp1);
	pa_push(&temp2, &temp1);
	pa_push(&temp2, &temp1);
	*stk_a = temp1;
	*stk_b = temp2;
}

// void	sort_5_element_list(t_stack **stk_a, t_stack **stk_b)
// {
// 	t_stack	*temp1;
// 	t_stack	*temp2;

// 	temp1 = *stk_a;
// 	temp2 = *stk_b;
// 	while (temp1 != NULL)
// 	{
// 		if (temp1->index == 0)
// 		{
// 			pb_push(&temp1, &temp2);
// 			break ;
// 		}
// 		ra_rb_rotate(&temp1, 'a');
// 	}
// 	while (temp1 != NULL)
// 	{
// 		if (temp1->index == 1)
// 		{
// 			pb_push(&temp1, &temp2);
// 			break ;
// 		}
// 		ra_rb_rotate(&temp1, 'a');
// 	}
// 	if (is_sorted(&temp1) == 0)
// 		sort_3_element_list(&temp1);
// 	pa_push(&temp2, &temp1);
// 	pa_push(&temp2, &temp1);
// 	*stk_a = temp1;
// 	*stk_b = temp2;
// }
//int find_median(t_stack **lst)
//{
//	int median;
//	int lst_size;
//	t_stack *temp;
//
//	temp = *lst;
//	median = 0;
//	lst_size = ft_lstsize(temp);
//	while (temp != NULL)
//	{
//		median = median + temp->index;
//		temp = temp->next;
//	}
//	return (median / lst_size);
//}
