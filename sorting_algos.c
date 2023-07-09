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

void sort_3_element_list(t_stack **stk_a) {
	t_stack *temp;
	temp = *stk_a;
	normalize_local_indexes(&temp);
//	printf("\nSort 3 says \n");
//
//	printf("\nStk a is \n");
	print_list(*stk_a);


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
	if (temp->local_index == 2) {
		temp = temp->next;
		if (temp->local_index == 0) {
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
		if (temp1->index == 0) {
			pb_push(&temp1, &temp2);
			break;
		}
		ra_rb_rotate(&temp1, 'a');
//		temp1 = temp1->next;
	}
//	printf("\nAfter finding and pushing smallest element to B \n");
//
//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);
	while (temp1 != NULL) {
		if (temp1->index == 1) {
			pb_push(&temp1, &temp2);
			break;
		}
		ra_rb_rotate(&temp1, 'a');
//		temp1 = temp1->next;
	}
//	printf("\nAfter two pushes to B \n");
//
//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);

//	printf("\nAfter finding and pushing next smallest element to B \n");
//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);
//	printf("\nSort3 on stack A \n");
	//normalize_local_indexes(&temp1);
	if (is_sorted(&temp1) == 0)
		sort_3_element_list(&temp1);

//	printf("\nAfter is_sorted and sort3 \n");
//
//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);


//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);

	pa_push(&temp2, &temp1);
	pa_push(&temp2, &temp1);
//	printf("\nAfter two pushes back to A \n");
//
//	printf("\nStk a is \n");
//	print_list(temp1);
//	printf("\nStk b is \n");
//	print_list(temp2);

	*stk_a = temp1;
	*stk_b = temp2;
}

int find_median(t_stack **lst)
{
	int median;
	int lst_size;
	t_stack *temp;

	temp = *lst;
	median = 0;
	lst_size = ft_lstsize(temp);
//	printf("LSTSIZe is %d", lst_size);
	while (temp != NULL)
	{
		median = median + temp->index;
		temp = temp->next;
	}
	return (median / lst_size);
}

void push_smallest_to_b(t_stack **stk_a, t_stack **stk_b)
{
//	printf("Push smallest to b!");
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;
	int operations;

	temp_a = *stk_a;
	temp_b = *stk_b;
	position = 0;
	normalize_local_indexes(&temp_a);
	lst_size = ft_lstsize(temp_a);
	operations = 0;
	while (temp_a->local_index != 0)
	{
		position++;
		temp_a = temp_a->next;
	}
	temp_a = *stk_a;

	if (position > lst_size / 2)
	{
		while (temp_a->local_index != 0)
		{
			rra_rotate(&temp_a);
			operations++;
		}

	}
	if (position <= lst_size / 2)
	{
		while (temp_a->local_index != 0)
		{
			ra_rb_rotate(&temp_a, 'a');
			operations++;

		}
	}
	pb_push(&temp_a, &temp_b);
//	printf("\nAfter pushing smallest node, resuls are  \n");
//	printf("\nNumber of operations %i \n", operations);
//
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);

	*stk_a = temp_a;
	*stk_b = temp_b;
}


void push_smallest_to_b_in_chunks(t_stack **stk_a, t_stack **stk_b, int max_size)
{
//	printf("Push smallest to b!");
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;
	int operations;
    int index;

	temp_a = *stk_a;
	temp_b = *stk_b;
    index = 0;
	position = 0;
	normalize_local_indexes(&temp_a);
	lst_size = ft_lstsize(temp_a);
	operations = 0;

    while (index != max_size && temp_a != NULL)
    {
//        printf("\nPush smallest to b chunks, index %d\n", index);
//        printf("\nMax size %d\n", max_size);
//        printf("\nStk a is \n");
//        print_list(temp_a);
//        printf("\nStk b is \n");
//        print_list(temp_b);
//        while (temp_a != NULL)
//        {
              if (temp_a->local_index != index)
              {
                rra_rotate(&temp_a);
              }
              if (temp_a->local_index == index)
              {
               pb_push(&temp_a, &temp_b);
               index++;
              }
        *stk_a = temp_a;
        *stk_b = temp_b;
//        }
    }
//    printf("\nAfter Push smallest to b chunks, index %d\n", index);



    *stk_a = temp_a;
    *stk_b = temp_b;

//    printf("\nStk a is \n");
//    print_list(temp_a);
//    printf("\nStk b is \n");
//    print_list(temp_b);
//    exit (1);
//
//    while (index >= max_size) {
//        while (temp_a->local_index != index) {
//            position++;
//            temp_a = temp_a->next;
//        }
//        temp_a = *stk_a;
//
//
//        if (position > lst_size / 2) {
//            while (temp_a->local_index != 0) {
//                rra_rotate(&temp_a);
//                operations++;
//            }
//
//        }
//        if (position <= lst_size / 2) {
//            while (temp_a->local_index != 0) {
//                ra_rb_rotate(&temp_a, 'a');
//                operations++;
//
//            }
//        }
//        pb_push(&temp_a, &temp_b);
//
//        index++;
//    }
    //	printf("\nAfter pushing smallest node, resuls are  \n");
//	printf("\nNumber of operations %i \n", operations);
//
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);
//
//	*stk_a = temp_a;
//	*stk_b = temp_b;
}

void push_smallest_to_a(t_stack **stk_a, t_stack **stk_b)
{
//	printf("Push smallest to b!");
	t_stack *temp_a;
	t_stack *temp_b;
	int position;
	int lst_size;
	int operations;

	temp_a = *stk_a;
	temp_b = *stk_b;
	position = 0;
	normalize_local_indexes(&temp_b);
	lst_size = ft_lstsize(temp_b);
	operations = 0;
	while (temp_b->local_index != 0)
	{
		position++;
		temp_b = temp_b->next;
	}
	temp_b = *stk_b;

	if (position > lst_size / 2)
	{
		while (temp_b->local_index != 0)
		{
			rra_rotate(&temp_b);
			operations++;
		}
	}
	if (position <= lst_size / 2)
	{
		while (temp_b->local_index != 0)
		{
			ra_rb_rotate(&temp_b, 'a');
			operations++;
		}
	}
	pa_push(&temp_b, &temp_a);
//	printf("\nAfter pushing smallest node, resuls are  \n");
//	printf("\nNumber of operations %i \n", operations);
//
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);

	*stk_a = temp_a;
	*stk_b = temp_b;
}

void sort_10(t_stack **stk_a, t_stack **stk_b)
{
//	printf("Sort 10!");
	t_stack *temp_a;
	t_stack *temp_b;
	int median;
	int operations;
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

//	printf("\nPush smallest to Stk B result is \n");
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);
	*stk_a = temp_a;
	*stk_b = temp_b;

//	exit(1);

}



void sort_big(t_stack **stk_a, t_stack **stk_b, int chunks)
{
//    printf("Sort 100!");
    t_stack *temp_a;
    t_stack *temp_b;
    int median;
    int operations = 0;
    int lst_size;
    temp_a = *stk_a;
    temp_b = *stk_b;
	int moves;



    lst_size = ft_lstsize(temp_a);
	int chunk_min_size = 3;
    int chunk_size;
	int last_chunk_size;
	while ((lst_size - 3) / chunks  < chunk_min_size)
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

//	while (((lst_size - 3) % chunks) >= 0 )
//	{
//		chunk_size = (lst_size - 3) / chunks;
//		last_chunk_size = (lst_size - 3) % chunks;
//
//		if (chunk_size * chunks + last_chu== 0)
//			chunks--;
//	}
    int current_chunk_size;
//	int last_chunk_size = (lst_size - 3) % chunks;

//	printf("\nList size is %d \n", lst_size);
//	printf("\nGonna use %d chunks\n", chunks);
//	printf("\nChunk size is %d \n", chunk_size);
//	printf("\nLast chunk is %d long \n", last_chunk_size);



	//exit (1);

	while (lst_size != 3 && chunks != 0)
    {
//        printf("\nChunk number %d \n", chunks);
//
//        printf("\nStk a is \n");
//        print_list(temp_a);
//        printf("\nStk b is \n");
//        print_list(temp_b);
        if (chunks == 1)
		{
	        current_chunk_size = last_chunk_size;
			moves = last_chunk_size;
        }
		if (chunks != 1) {
			current_chunk_size = chunk_size;
			moves = chunk_size;
		}
	    while (moves != 0)
        {
//            printf("\nStuck here \n");

//            if (is_reverse_sorted(&temp_b) == 0 || &temp_b == NULL)
//            {
//                printf("\nTemp b size is %d \n", ft_lstsize(temp_b));
//                printf("\nCurrent chunk size is  %d\n", current_chunk_size);
                push_smallest_to_b_in_chunks(&temp_a, &temp_b, (ft_lstsize(temp_b) + current_chunk_size));
//            }
//            push_smallest_to_b(&temp_a, &temp_b);

//            printf("\ncCunk %d \n", chunks);
//            printf("\nMoves is %d\n", moves);
//            printf("\nListsize is %d\n", lst_size);
//            printf("\nCurrent Chunk size  is %d\n", current_chunk_size);


            moves--;
            lst_size--;
			operations++;
        }

        chunks--;

    }
//	printf("\nFinished push smallest to B, starting sort 3 on stack A \n");
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);
//	printf("\nOperations : %d \n", operations);

//    if (is_sorted(&temp_a) == 0)
//		sort_3_element_list(&temp_a);

//	printf("\nFinished sort 3 on stack A \n");
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);


	operations = operations + 8;
    lst_size = ft_lstsize(temp_b);
    while (lst_size != 0)
    {
        pa_push(&temp_b, &temp_a);
		operations++;
        lst_size--;
    }
//
//    printf("\nEnd of sort_big is \n");
////
//    printf("\nStk a is \n");
//    print_list(temp_a);
//    printf("\nStk b is \n");
//    print_list(temp_b);
//	printf("\nOperations : %d \n", operations);

    *stk_a = temp_a;
    *stk_b = temp_b;

//	exit(1);
}

//
//void sort_big(t_stack **stk_a, t_stack **stk_b, int chunks)
//{
//	printf("Sort 100!");
//	t_stack *temp_a;
//	t_stack *temp_b;
//	int median;
//	int operations;
//	int lst_size;
//	temp_a = *stk_a;
//	temp_b = *stk_b;
//
//	lst_size = ft_lstsize(temp_a);
//	int chunk_size = lst_size / chunks;
//	int current_chunk_size;
//
//	while (lst_size != 3)
//	{
//		current_chunk_size = chunk_size;
//		while (chunk_size != 0 & lst_size != 3)
//		{
//			push_smallest_to_b(&temp_a, &temp_b);
//			current_chunk_size--;
//			lst_size--;
//		}
//	}
//	sort_3_element_list(&temp_a);
//	lst_size = ft_lstsize(temp_b);
//	while (lst_size != 0)
//	{
//		pa_push(&temp_b, &temp_a);
//		lst_size--;
//	}
//
//	printf("\nPush smallest to Stk B result is \n");
//
//	printf("\nStk a is \n");
//	print_list(temp_a);
//	printf("\nStk b is \n");
//	print_list(temp_b);
//	*stk_a = temp_a;
//	*stk_b = temp_b;
//
//}



void random_sort1(t_stack **lst)
{
	t_stack	*temp;
	temp = *lst;

	sa_sb_swap(lst, 'a');
}
void random_sort2(t_stack **lst)
{
	t_stack	*temp;
	temp = *lst;

	ra_rb_rotate(lst, 'a');
}

void sorting_algos(t_stack **lst, t_stack **stk_b, int randomvalue)
{
	t_stack	*temp;
	temp = *lst;
	int lst_size;

	lst_size = ft_lstsize(temp);


	if (temp == NULL || temp->next == NULL)
		return ;
	if (lst_size == 2)
	{
		sort_2_element_list(lst, 'a');
	}
	if (lst_size == 3)
	{
		sort_3_element_list(lst);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);

	}
	if (lst_size == 5)
	{
		sort_5_element_list(lst, stk_b);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);
	}

	if (lst_size > 5 && lst_size <= 12)
	{
		sort_10(lst, stk_b);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);
	}
	if (lst_size > 12 && lst_size <= 15)
	{
		sort_big(lst, stk_b, 3);
	}
//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);

//	if (lst_size == 15)
//	{
//		sort_big(lst, stk_b, lst_size / 3);
//	}
//
////	if (lst_size > 10 && lst_size <= 100)
////	{
////		sort_big(lst, stk_b, lst_size / 4);
////	}

	if (lst_size > 15 && lst_size < 100)
	{
		sort_big(lst, stk_b, 3);

//		if (randomvalue > 1073741823)
//			random_sort1(lst);
//		if (randomvalue < 1073741823)
//			random_sort2(lst);
	}
	if (lst_size == 100)
	{
		sort_big(lst, stk_b, 4);
	}

//	if (lst_size > 100 && lst_size <= 500)
//	{
//		sort_big(lst, stk_b, 62);
//	}
	if (lst_size == 500)
	{
		sort_big(lst, stk_b, 11);
	}
}



t_stack* copy_list(t_stack* head)
{
	if (head == NULL)
		return NULL; // Return NULL for an empty list

	t_stack* new_head = NULL; // Head of the new list
	while (head != NULL)
	{
		ft_lstadd_back(&new_head, (ft_lstnew(head->content)));
		head = head->next;
	}
	return new_head;
}

// 1 is sorted, 0 is not sorted
int is_sorted(t_stack **lst)
{
	t_stack *temp1;
	temp1 = *lst;
    if (temp1 == NULL)
        return (0);
	while (temp1->next != NULL)
	{
		if (temp1->content > temp1->next->content)
		{
			return (0);
		}
		temp1 = temp1->next;
	}
	return (1);
}

int is_reverse_sorted(t_stack **lst)
{
    t_stack *temp1;
    temp1 = *lst;

    if (temp1 == NULL)
        return (0);
    while (temp1->next != NULL)
    {
        if (temp1->content < temp1->next->content)
        {
            return (0);
        }
        temp1 = temp1->next;
    }
    return (1);
}
