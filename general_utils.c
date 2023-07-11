/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:48:26 by mrizakov          #+#    #+#             */
/*   Updated: 2023/07/11 17:45:18 by mrizakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	str_len;
	unsigned int	correct_size;

	i = 0;
	str_len = ft_strlen((char *)s);
	correct_size = 1;
	if (start > str_len || len == 0)
		correct_size = 1;
	else if (len <= str_len - start)
		correct_size = len + 1;
	else if (len > str_len - start)
		correct_size = str_len - start + 1;
	substr = malloc(correct_size * sizeof(char));
	if (!substr)
		return ((void *) NULL);
	while (i != correct_size - 1)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	unsigned int	word_count;
	unsigned int	i;
	unsigned int	len;
	unsigned int	y;

	word_count = ft_word_count(s, c);
	y = -1;
	i = 0;
	array = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (++y < word_count)
	{
		while (s[i] == c)
			i++;
		len = ft_size_word(s, c, i);
		array[y] = ft_substr(s, i, len);
		if (!array[y])
			ft_free(array, y);
		i = i + len;
	}
	array[y] = 0;
	return (array);
}

void	clean_ptrs(char **double_ptr)
{
	char	**tmp;

	tmp = double_ptr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(double_ptr);
}

long long	ft_long_long_atoi(const char *str)
{
	long long	result;
	int			positive;

	positive = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		positive = -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str != '\0')
		while (*str >= 48 && *str <= 57)
			result = result * 10 + *str++ - '0';
	return (result * positive);
}
