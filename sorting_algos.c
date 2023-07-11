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

void sort_2_element_list(t_stack **lst, int flag)
{
	sa_sb_swap(lst, flag);
}

void sort_3_element_list(t_stack **stk_a)
{
	t_stack *temp;
	temp = *stk_a;
	normalize_local_indexes(&temp);

	if (temp->local_index == 0) {
		sa_sb_swap(stk_a, 'a');
		ra_rb_rotate(stk_a, 'a');
		return;
	}
	if (temp->local_index == 1) {
		temp = temp->next;
		if (temp->local_index == 0) {
			sa_sb_swap(stk_a, 'a');
			return;
		}
		if (temp->local_index == 2) {
			rra_rotate(stk_a);
			return;
		}
	}
	if (temp->local_index == 2)
	{
		temp = temp->next;
		if (temp->local_index == 0)
		{
			ra_rb_rotate(stk_a, 'a');
			return;
		}
		if (temp->local_index == 1)
			sa_sb_swap(stk_a, 'a');
		rra_rotate(stk_a);
	}
}

void sort_5_element_list(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *temp1;
	temp1 = *stk_a;
	t_stack *temp2;
	temp2 = *stk_b;

	while (temp1 != NULL) {
		if (temp1->index == 0)
		{
			pb_push(&temp1, &temp2);
			break;
		}
		ra_rb_rotate(&temp1, 'a');
	}
	while (temp1 != NULL)
	{
		if (temp1->index == 1)
		{
			pb_push(&temp1, &temp2);
			break;
		}
		ra_rb_rotate(&temp1, 'a');
	}
	if (is_sorted(&temp1) == 0)
		sort_3_element_list(&temp1);
	pa_push(&temp2, &temp1);
	pa_push(&temp2, &temp1);
	*stk_a = temp1;
	*stk_b = temp2;
}

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

void push_smallest_to_b(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;

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
	{
		while (temp_a->local_index != 0)
			rrb_rotate(&temp_a);
	}
	if (position <= lst_size / 2)
	{
		while (temp_a->local_index != 0)
			ra_rb_rotate(&temp_a, 'a');
	}
	pb_push(&temp_a, &temp_b);
	*stk_a = temp_a;
	*stk_b = temp_b;
}

void push_smallest_to_b_in_chunks(t_stack **stk_a, t_stack **stk_b, int max_size)
{
	t_stack *temp_a;
	t_stack *temp_b;
    static int index;
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

void push_biggest_to_a(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;
	position = 0;
	temp_a = *stk_a;
	temp_b = *stk_b;
	normalize_local_indexes(&temp_b);
	lst_size = ft_lstsize(temp_b);
	if (temp_b == NULL)
		return ;
	while (temp_b->index != lst_size - 1)
	{
		position++;
		temp_b = temp_b->next;
	}
	temp_b = *stk_b;
	if (position > lst_size / 2)
	{
		while (temp_b->index != lst_size - 1)
			rrb_rotate(&temp_b);
	}
	if (position <= lst_size / 2)
	{
		while (temp_b->index != lst_size - 1)
			ra_rb_rotate(&temp_b, 'b');
	}
	pa_push(&temp_b, &temp_a);
	*stk_a = temp_a;
	*stk_b = temp_b;
}

void sort_10(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int lst_size;
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

void sort_big(t_stack **stk_a, t_stack **stk_b, int chunks)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int lst_size;
	temp_a = *stk_a;
	temp_b = *stk_b;

	lst_size = ft_lstsize(temp_a);
	int chunk_min_size = 3;
	int chunk_size;
	int last_chunk_size;

	while ((lst_size - 3) / chunks < chunk_min_size)
		chunks++;
	chunk_size = (lst_size - 3) / chunks;

	if ((lst_size - 3) % chunks == 0)
		last_chunk_size = chunk_size;

	if ((lst_size - 3) % chunks != 0)
	{
		chunk_size = (lst_size - 3) / chunks;
		last_chunk_size = (lst_size - 3) - (chunk_size * chunks);
		chunks++;
	}
	int current_chunk_size = -1;
	while (chunks != 0)
	{
		if (chunks == 1)
			current_chunk_size = current_chunk_size + last_chunk_size;
		if (chunks != 1)
			current_chunk_size = current_chunk_size + chunk_size;
		push_smallest_to_b_in_chunks(&temp_a, &temp_b, current_chunk_size);
		lst_size = ft_lstsize(temp_a);
		lst_size--;
		chunks--;
	}
	if (is_sorted(&temp_a) == 0)
		sort_3_element_list(&temp_a);
	while (temp_b != NULL)
		push_biggest_to_a(&temp_a, &temp_b);
    *stk_a = temp_a;
    *stk_b = temp_b;
}

void sorting_algos(t_stack **lst, t_stack **stk_b)
{
	t_stack	*temp;
	temp = *lst;
	int lst_size;
	lst_size = ft_lstsize(temp);
	if (temp == NULL || temp->next == NULL)
		return ;
	if (lst_size == 2)
		sort_2_element_list(lst, 'a');
	if (lst_size == 3)
		sort_3_element_list(lst);
	if (lst_size == 5)
		sort_5_element_list(lst, stk_b);
	if (lst_size > 5 && lst_size <= 12)
		sort_10(lst, stk_b);
	if (lst_size > 12 && lst_size <= 15)
		sort_big(lst, stk_b, 3);
	if (lst_size > 15 && lst_size < 100)
		sort_big(lst, stk_b, 3);
	if (lst_size == 100)
		sort_big(lst, stk_b, 4);
	if (lst_size == 500)
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

int is_sorted(t_stack **lst)
{
	t_stack *temp1;
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
