/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:54:29 by mrizakov          #+#    #+#             */
/*   Updated: 2023/06/27 12:55:02 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_handler_and_parser(t_stack **stk_a, int argc, char **argv)
{
	int		i;
	char	**checked_values;

	i = 1;
	if (argc < 2)
		return (1);
	while (i + 1 <= argc)
	{
		checked_values = ft_split(argv[i], ' ');
		if (!(checked_values))
		{
			free(checked_values);
			exit(1);
		}
		ft_error_checker(checked_values, stk_a);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = NULL;
	stk_b = NULL;
	if (ft_error_handler_and_parser(&stk_a, argc, argv) == 1)
	{
		free_list(stk_a);
		return (1);
	}
	normalize_indexes(&stk_a);
	while (is_sorted(&stk_a) == 0)
		sorting_algos(&stk_a, &stk_b);
	if (is_sorted(&stk_a) == 1)
	{
		printf("\nStk a is \n");
		print_list(stk_a);
		printf("\nStk b is \n");
		print_list(stk_b);
		printf("Sorted!");
	}
	free_list(stk_a);
	free_list(stk_b);
	return (0);
}
