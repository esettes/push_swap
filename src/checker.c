/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/26 23:12:44 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_correct_chars(char **argv);
int	are_all_integers(long int *arr, int i);

int	is_valid_arg(char **argv, int argc)
{
	char 		*ptr;
	long int	ret;
	int 		i;

	i = 1;
	if (argv[1] == NULL)
		return (0);
	while (argv[i])
	{
		ptr = NULL;
		ret = ft_strtol(argv[i], &ptr, 10);

		if (*ptr)
			return (0);
		i++;
	}
	return (1);
}

// int	is_valid_arg(char **argv, int argc)
// {
// 	long int	*arr;
// 	int			i;
// 	int			j;

// 	j = 0;
// 	if (!are_correct_chars(argv))
// 		return (0);
// 	arr = malloc(sizeof(long int) * argc);
// 	if (!arr)
// 		return (0);
// 	i = argc;
// 	while (argc-- > 0 && argv[j + 1])
// 	{
// 		arr[j] = ft_atoi(argv[j + 1]);
// 		j++;
// 	}
// 	j = 0;
// 	if (!are_all_integers(arr, i))
// 		return (0);
// 	free (arr);
// 	return (1);
// }

int	is_sorted_stack(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (*head)
	{
		current = *head;
		next = current->next;
		while (next != NULL)
		{
			if (current->data > next->data)
				return (0);
			current = current->next;
			next = current->next;
		}
		return (1);
	}
	return (0);
}

int	is_reverse_sorted(t_node **head)
{
	t_node	*current;
	t_node	*next;

	if (*head)
	{
		current = *head;
		next = current->next;
		while (next != NULL)
		{
			if (current->data < next->data)
				return (0);
			current = current->next;
			next = current->next;
		}
		return (1);
	}
	return (0);
}

int	is_duplicated_arg(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current->next != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->data == next->data)
				return (1);
			next = next->next;
		}
		current = current->next;
	}
	return (0);
}
