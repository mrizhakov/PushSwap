/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/15 21:58:31 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_biggest_to_a(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		position;
	int		lst_size;

	position = 0;
	temp_a = *stk_a;
	temp_b = *stk_b;
	normalize_local_indexes(&temp_b);
	lst_size = ft_lstsize(temp_b);
	while (temp_b->index != lst_size - 1)
	{
		position++;
		temp_b = temp_b->next;
	}
	temp_b = *stk_b;
	if (position > lst_size / 2)
		while (temp_b->index != lst_size - 1)
			rrb_rotate(&temp_b);
	if (position <= lst_size / 2)
		while (temp_b->index != lst_size - 1)
			ra_rb_rotate(&temp_b, 'b');
	pa_push(&temp_b, &temp_a);
	*stk_a = temp_a;
	*stk_b = temp_b;
}

// void	push_biggest_to_a(t_stack **stk_a, t_stack **stk_b)
// {
// 	t_stack	*temp_a;
// 	t_stack	*temp_b;
// 	int		position;
// 	int		lst_size;

// 	position = 0;
// 	temp_a = *stk_a;
// 	temp_b = *stk_b;
// 	normalize_local_indexes(&temp_b);
// 	lst_size = ft_lstsize(temp_b);
// 	if (temp_b == NULL)
// 		return ;
// 	while (temp_b->index != lst_size - 1)
// 	{
// 		position++;
// 		temp_b = temp_b->next;
// 	}
// 	temp_b = *stk_b;
// 	if (position > lst_size / 2)
// 		while (temp_b->index != lst_size - 1)
// 			rrb_rotate(&temp_b);
// 	if (position <= lst_size / 2)
// 		while (temp_b->index != lst_size - 1)
// 			ra_rb_rotate(&temp_b, 'b');
// 	pa_push(&temp_b, &temp_a);
// 	*stk_a = temp_a;
// 	*stk_b = temp_b;
// }

void	sort_10(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		lst_size;

	temp_a = *stk_a;
	temp_b = *stk_b;
	lst_size = ft_lstsize(temp_a);
	while (lst_size != 3)
	{
		push_smallest_to_b(&temp_a, &temp_b);
		lst_size--;
	}
	sort_3_element_list(&temp_a);
	lst_size = ft_lstsize(temp_b);
	while (lst_size != 0)
	{
		pa_push(&temp_b, &temp_a);
		lst_size--;
	}
	*stk_a = temp_a;
	*stk_b = temp_b;
}

void	adjust_chunk_size(t_stack **stk_a, t_stack **stk_b, int chunks)
{
	int		chunk_size;
	int		last_chunk_size;
	int		current_chunk_size;

	while ((ft_lstsize(*stk_a) - 3) / chunks < 3)
		chunks++;
	chunk_size = (ft_lstsize(*stk_a) - 3) / chunks;
	if ((ft_lstsize(*stk_a) - 3) % chunks == 0)
		last_chunk_size = chunk_size;
	if ((ft_lstsize(*stk_a) - 3) % chunks != 0)
	{
		chunk_size = (ft_lstsize(*stk_a) - 3) / chunks;
		last_chunk_size = (ft_lstsize(*stk_a) - 3) - (chunk_size * chunks);
		chunks++;
	}
	current_chunk_size = -1;
	while (chunks != 0)
	{
		if (chunks == 1)
			current_chunk_size = current_chunk_size + last_chunk_size;
		if (chunks != 1)
			current_chunk_size = current_chunk_size + chunk_size;
		push_smallest_to_b_in_chunks(stk_a, stk_b, current_chunk_size);
		chunks--;
	}
}

void	sort_big(t_stack **stk_a, t_stack **stk_b, int chunks)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stk_a;
	temp_b = *stk_b;
	adjust_chunk_size(&temp_a, &temp_b, chunks);
	if (is_sorted(&temp_a) == 0)
		sort_3_element_list(&temp_a);
	while (temp_b != NULL)
		push_biggest_to_a(&temp_a, &temp_b);
	*stk_a = temp_a;
	*stk_b = temp_b;
}

//void	divide_in_chunks(t_stack **stk_a, t_stack **stk_b, int chunks)
//{
//
//}
void	sorting_algos(t_stack **lst, t_stack **stk_b)
{
	t_stack	*temp;
	int		lst_size;

	temp = *lst;
	lst_size = ft_lstsize(temp);
	if (temp == NULL || temp->next == NULL)
		return ;
	if (lst_size == 2)
		sort_2_element_list(lst, 'a');
	if (lst_size == 3)
		sort_3_element_list(lst);
	if (lst_size == 4)
		sort_4_element_list(lst, stk_b);
	if (lst_size == 5)
		sort_5_element_list(lst, stk_b);
	if (lst_size > 5 && lst_size <= 12)
		sort_big(lst, stk_b, 1);
	if (lst_size > 12 && lst_size <= 15)
		sort_big(lst, stk_b, 3);
	if (lst_size > 15 && lst_size <= 100)
		sort_big(lst, stk_b, 4);
	if (lst_size > 100 && lst_size < 500)
		sort_big(lst, stk_b, 8);
	if (lst_size >= 500)
		sort_big(lst, stk_b, 12);
}

//t_stack* copy_list(t_stack* head)
//{
//	if (head == NULL)
//		return NULL;
//
//	t_stack* new_head = NULL;
//	while (head != NULL)
//	{
//		ft_lstadd_back( &new_head, (ft_lstnew(head->content)));
//		head = head->next;
//	}
//	return new_head;
//}
//
//int is_reverse_sorted(t_stack **lst)
//{
//    t_stack *temp1;
//    temp1 = *lst;
//
//    if (temp1 == NULL)
//        return (0);
//    while (temp1->next != NULL)
//    {
//        if (temp1->content < temp1->next->content)
//        {
//            return (0);
//        }
//        temp1 = temp1->next;
//    }
//    return (1);
//}
