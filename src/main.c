/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:52 by iostancu          #+#    #+#             */
/*   Updated: 2023/05/02 20:08:30 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fcntl.h"

int		is_correct_argument(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	if (is_valid_arg(argv, argc))
	{
		stack = alloc_stacks(argc, argv);
		if (!stack)
			return (0);
		if (is_correct_argument(stack))
		{
			set_index_to_each_elem(stack);
			if (stack->elements <= 3)
				sort_three_elems(stack, stack->a);
			f_insertion_sort(stack);
			free(stack->b_elems);
		}
		free_entire_stack(stack);
	}
	else
	{
		ft_putendl_fd(RED_, "Error", 2);
		return (0);
	}
	return (1);
}

int	is_correct_argument(t_stack *stack)
{
	if (is_duplicated_arg(&stack->a))
	{
		ft_putendl_fd(RED_, "Error", 2);
		return (0);
	}
	if (is_sorted_stack(&stack->a))
	{
		return (0);
	}
	return (1);
}

void	free_stack(t_node **head)
{
	t_node	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void	free_entire_stack(t_stack *stack)
{
	if (stack->a)
		free_stack(&stack->a);
	if (stack->b)
		free_stack(&stack->b);
	free(stack);
}
