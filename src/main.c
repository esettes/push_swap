/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:52 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/25 20:25:03 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fcntl.h"

int		is_correct_argument(t_stack *stack);
long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
void	free_stack(t_node **head);

int		main(int argc, char **argv)
{
	t_stack	*stack;
	int		fd;
	char	**input;
	int 	i;

	i = 0;
	if (is_valid_arg(argv, argc))
	{
		stack = alloc_stacks(argc, argv);
		if (!stack)
			return (0);
		if (is_correct_argument(stack))
		{
			set_index_to_each_elem(stack);
			//f_bucket_sort(stack);
			//sort_three_elems(stack, stack->a);
			//push_all_elems_except_last_three(stack);
			f_insertion_sort(stack);
		}
		else
		{
			//ft_putendl_fd(RED_,"Error", 2);
		}
		free_stack(&stack->a);
		free_stack(&stack->b);
		free(stack);
	}
	else
	{
		ft_putendl_fd(RED_,"Error", 2);
		return (0);
	}
	return (1);
}

int		is_correct_argument(t_stack *stack)
{
	if (is_sorted_stack(&stack->a))
	{
		return (0);
	}
	if (is_duplicated_arg(&stack->a))
	{
		ft_putendl_fd(RED_,"Error", 1);
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
