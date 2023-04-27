/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 22:02:17 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		are_all_integers(long int *arr, int i);

int	is_valid_arg(char **argv, int argc)
{
	long int	*arr;
	t_iter		it;
	t_iter		arg;
	char		**tmp;
	int			all_args;

	if (!are_correct_chars(argv))
		return (0);
	all_args = count_all_args(argc, argv);
	arr = malloc(sizeof(long int) * all_args);
	if (!arr)
		return (0);
	set_all_args(argc, argv, arr);
	if (!are_all_integers(arr, all_args))
		return (0);
	free (arr);
	return (1);
}

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
