/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 21:49:08 by iostancu         ###   ########.fr       */
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
	printf("all_args: %i \n", all_args);
	arr = malloc(sizeof(long int) * all_args + 1);
	if (!arr)
		return (0);
	set_all_args(argc, argv, arr);
	
	
	// it.j = 0;
	// arg.i = 0;
	// while (all_args > 0 && argv[it.j + 1])
	// {
	// 	it.i = str_count(argv[it.j + 1], ' ');
	// 	if (it.i > 1)
	// 	{
	// 		arg.j = 0;
	// 		tmp = ft_split(argv[it.j + 1], ' ');
	// 		while (--it.i > 0)
	// 			arr[arg.i++] = ft_atoi(tmp[arg.j++]);
	// 		it.j++;
	// 		free (tmp);
	// 	}
	// 	else
	// 	{
	// 		arr[arg.i++] = ft_atoi(argv[it.j + 1]);
	// 		it.j++;
	// 	}
	// 	all_args--;
	// }
	// arr[arg.i] = 0;
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
