/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2008/04/23 00:02:23 by aron              #+#    #+#             */
/*   Updated: 2023/06/27 12:55:06 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack {
	int content;
	int index;
	int local_index;
	struct s_stack *next;
} t_stack;

int         ft_isdigit(int c);
void        ft_putchar_fd(char c, int fd);
void        ft_putstr_fd(char *s, int fd);
void        ft_putstr_fd(char *s, int fd);
char        **ft_free(char **strs, int j);
int         ft_word_count(const char *str, char c);
int         ft_size_word(const char *s, char c, int i);
char        **ft_split(char const *s, char c);
char        **ft_free_split(char **strs);
void        clean_ptrs(char **double_ptr);
size_t      ft_strlen(const char *str);
char        *ft_substr(char const *s, unsigned int start, size_t len);
int         ft_isdigit2(const char *str);
long long   ft_long_long_atoi(const char *str);
void        ft_lstadd_back(t_stack **lst, t_stack *new);
void        ft_lstadd_front(t_stack **lst, t_stack *new);
void        ft_lstclear(t_stack **lst, void (*del)(void *));
void        ft_lstdelone(t_stack *lst, void (*del)(void *));
void        ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack     *ft_lstlast(t_stack *lst);
t_stack     *ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
t_stack     *ft_lstnew(int content);
int         ft_lstsize(t_stack *lst);
void        free_list(t_stack *head);
void        print_list(t_stack *head);
int         ft_lstsize(t_stack *lst);
void        ft_sort_int_tab(int *tab, int size);
t_stack     *swap_nodes_by_value(t_stack **head, int val1, int val2);
t_stack     *swap_nodes_by_index(t_stack **head, int index1, int index2);
void        bubble_sort(t_stack **head);
int         ft_check_ll_doubles(t_stack **lst, int new);
int         ft_error_handler_and_parser(t_stack **stk_a, int argc, char **argv);
int         ft_number_checker(const char *str);

t_stack     *reassign_first_element(t_stack* source_list, t_stack* target_list);
t_stack     *pop_head(t_stack **lst);
t_stack     *pop_tail(t_stack **lst);
void    sa_sb_swap(t_stack **head, char flag);
void    ss_swap(t_stack **head1, t_stack **head2, char flag);
void    pa_push(t_stack **head_src, t_stack **head_dest);
void    pb_push(t_stack **head_src, t_stack **head_dest);

void	ra_rb_rotate(t_stack **lst, char flag);
void	rr_rotate(t_stack **lst1, t_stack **lst2, char flag);

void	rra_rotate(t_stack **lst);
void	rrb_rotate(t_stack **lst);
void	rrr_rotate(t_stack **lst1, t_stack**lst2);
void    pb_push(t_stack **head_src, t_stack **head_dest);
void    pa_push(t_stack **head_src, t_stack **head_dest);

void normalize_indexes(t_stack **head);
void normalize_local_indexes(t_stack **head);
void print_list_with_indexes(t_stack **head);
void sorting_algos(t_stack **stk_a, t_stack **stk_b);
void sort_big(t_stack **stk_a, t_stack **stk_b, int chunks);

void sort_2_element_list(t_stack **lst, int flag);
void sort_3_element_list(t_stack **stk_a);
void sort_5_element_list(t_stack **stk_a, t_stack **stk_b);

int is_sorted(t_stack **lst);
void copy_linked_list(t_stack **lst, t_stack **copy_lst);
t_stack* copy_list(t_stack* head);
void random_sort1(t_stack **lst);
void random_sort2(t_stack **lst);
void free_list2(t_stack** head);
void push_smallest_to_b(t_stack **stk_a, t_stack **stk_b);
void push_smallest_to_a(t_stack **stk_a, t_stack **stk_b);
void push_smallest_to_b_in_chunks(t_stack **stk_a, t_stack **stk_b, int max_size);
int is_reverse_sorted(t_stack **lst);
void push_biggest_to_a(t_stack **stk_a, t_stack **stk_b);
void ft_error_checker(char **checked_values, t_stack **stk_a);







#endif //PUSH_SWAP_H
