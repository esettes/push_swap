/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:04:07 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/26 17:37:38 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_index_of_last_elem(t_node *stack);
void	return_elems_and_sort(t_stack *stack);

void	f_insertion_sort(t_stack *stack)
{
	t_temp	node;
	int		current_elems;
	int		b_index;

	b_index = 0;
	current_elems = count_stack_elements(stack->a);
	while (stack->a && current_elems > 3)
	{
		while (are_elems_of_current_bucket_in_stack(stack->a, b_index)
			&& current_elems > 3)
		{
			node.top = get_node_position_from_top(stack, stack->a, b_index);
			node.bottom = get_node_position_from_bottom(stack, stack->a,
					b_index, current_elems);
			do_less_rotation_moves_a(node, stack, &stack->a);
			print_both_stacks(stack);
			f_push(&stack->a, &stack->b, stack, 2);
			current_elems = count_stack_elements(stack->a);
		}
		b_index++;
	}
	return_elems_and_sort(stack);
}

int	get_index_of_last_elem(t_node *stack)
{
	while (stack && stack->next)
	{
		stack = stack->next;
	}
	return (stack->index);
}

void	return_elems_and_sort(t_stack *stack)
{
	if (return_biggest_elems_from_b(stack, stack->b))
	{
		f_reverse_rotate(&stack->b, stack, 0, 1);
		f_push(&stack->b, &stack->a, stack, 1);
	}
	if (stack->elements >= 3)
		sort_three_elems(stack, stack->a);
	sort_stack_a(stack);
}
