/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 17:47:11 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *str)
{
	long long	result;
	int			positive;

	positive = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		positive = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		while (*str >= 48 && *str <= 57)
			result = result * 10 + *str++ - '0';
	}
	return (0);
}

int	ft_is_min_max_int(char *str)
{
	long long	result;
	int			positive;

	positive = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
		positive = -1;
	if (*str == 45 || *str == 43)
		str++;
	while (*str)
		while (*str >= 48 && *str <= 57)
			result = result * 10 + *str++ - '0';
	if (result * positive > INT_MAX || result * positive < INT_MIN)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}

void	ft_error_checker(char **arr, t_stack **stk_a)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if ((ft_is_number(arr[i]) == 1)
			|| ft_is_min_max_int(arr[i]) == 1
			|| ft_check_ll_doubles(stk_a, ft_long_long_atoi(arr[i])) == 1)
		{
			free_list(*stk_a);
			clean_ptrs(arr);
			exit (1);
		}
		ft_lstadd_back(stk_a, ft_lstnew(ft_long_long_atoi(arr[i])));
		i++;
	}
	clean_ptrs(arr);
}
