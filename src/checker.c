/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/21 22:45:44 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	is_valid_arg(char **argv)
// {
// 	char 		*ptr;
// 	long int	ret;
// 	int 		i;
	
// 	i = 1;
// 	if (argv[1] == NULL)
// 		return (0);
// 	while (argv[i])
// 	{
// 		ptr = NULL;
// 		ret = ft_strtol(argv[i], &ptr, 10);
// 		if (*ptr)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	is_valid_arg(char **argv)
{
	char		**arr;
	char 		*ptr;
	long int	ret;
	int 		i;
	int			j;

	arr = ft_split(argv[1], ' ');
	
	j = 0;
	if (argv[1] == NULL)
		return (0);
	while (arr[j][i])
	{
		printf("%s \n", arr[j]);
		j++;
	}
	free (arr);
	return (1);
}

int	is_sorted_stack(t_node **head)
{
	t_node *current;
	t_node *next;

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
	t_node *current;
	t_node *next;

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
	t_node *current;
	t_node *next;

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
