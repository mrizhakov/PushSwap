/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 22:58:27 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_smallest_to_b(t_stack	**stk_a, t_stack	**stk_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		position;
	int		lst_size;

	temp_a = *stk_a;
	temp_b = *stk_b;
	position = 0;
	normalize_local_indexes(&temp_a);
	lst_size = ft_lstsize(temp_a);
	while (temp_a->local_index != 0)
	{
		position++;
		temp_a = temp_a->next;
	}
	temp_a = *stk_a;
	if (position > lst_size / 2)
		while (temp_a->local_index != 0)
			rra_rotate(&temp_a);
	if (position <= lst_size / 2)
		while (temp_a->local_index != 0)
			ra_rb_rotate(&temp_a, 'a');
	pb_push(&temp_a, &temp_b);
	*stk_a = temp_a;
	*stk_b = temp_b;
}

void	push_smallest_to_b_in_chunks(t_stack	**stk_a, 
	t_stack	**stk_b, int max_size)
{
	t_stack			*temp_a;
	t_stack			*temp_b;
	static int		index;

	temp_a = *stk_a;
	temp_b = *stk_b;
	normalize_local_indexes(&temp_a);
	while (index <= max_size && temp_a != NULL)
	{
		while (temp_a->index > max_size)
			rra_rotate(&temp_a);
		if (temp_a->index <= max_size)
		{
			pb_push(&temp_a, &temp_b);
			index++;
		}
		*stk_a = temp_a;
		*stk_b = temp_b;
	}
	*stk_a = temp_a;
	*stk_b = temp_b;
}

void	pb_two_smallest_elements(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;

	temp1 = *stk_a;
	temp2 = *stk_b;
	i = 0;
	while (temp1 != NULL)
	{
		if (temp1->index == 0)
		{
			pb_push(&temp1, &temp2);
			i++;
		}
		if (temp1->index == 1 && i == 1)
		{
			pb_push(&temp1, &temp2);
			break ;
		}
		ra_rb_rotate(&temp1, 'a');
	}
	*stk_a = temp1;
	*stk_b = temp2;
}

int	is_sorted(t_stack **lst)
{
	t_stack	*temp1;

	temp1 = *lst;
	if (temp1 == NULL)
		return (0);
	while (temp1->next != NULL)
	{
		if (temp1->content > temp1->next->content)
			return (0);
		temp1 = temp1->next;
	}
	return (1);
}

void	sort_4_element_list(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	push_smallest_to_b(stk_a, stk_b);
	temp1 = *stk_a;
	temp2 = *stk_b;
	if (is_sorted(&temp1) == 0)
		sort_3_element_list(&temp1);
	pa_push(&temp2, &temp1);
	*stk_a = temp1;
	*stk_b = temp2;
}

//
//void push_smallest_to_a(t_stack **stk_a, t_stack **stk_b)
//{
//	t_stack *temp_a;
//	t_stack *temp_b;
//	int position;
//	int lst_size;
//	position = 0;
//	temp_a = *stk_a;
//	temp_b = *stk_b;
//	normalize_local_indexes(&temp_b);
//
//	lst_size = ft_lstsize(temp_b);
//	if (temp_b == NULL)
//		return ;
//	while (temp_b->local_index != 0)
//	{
//		position++;
//		temp_b = temp_b->next;
//	}
//	temp_b = *stk_b;
//	if (position > lst_size / 2)
//	{
//		while (temp_b->local_index != 0)
//			rrb_rotate(&temp_b);
//	}
//	if (position <= lst_size / 2)
//	{
//		while (temp_b->local_index != 0)
//			ra_rb_rotate(&temp_b, 'a');
//	}
//	pa_push(&temp_b, &temp_a);
//	*stk_a = temp_a;
//	*stk_b = temp_b;
//}
