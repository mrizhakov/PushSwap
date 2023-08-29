/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_LLutils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 21:06:19 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	ft_putstr_fd("Value   Index   Local index\n", 1);
	while (temp != NULL)
	{
		printf("%d         ", temp->content);
		printf("%d         ", temp->index);
		printf("%d\n", temp->local_index);
		temp = temp->next;
	}
}
