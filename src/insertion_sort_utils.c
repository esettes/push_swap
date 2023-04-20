/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:10:47 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/20 21:11:53 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_elements(t_node *node)
{
	t_node	*current;
	int		i;

	i = 0;
	current = node;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}


void	put_least_elem_of_b_to_head(t_stack *stack, int b_index)
{
	t_node	*tmp;
	int		max_val;
	int		elems;

	elems = count_stack_elements(stack->b);
	tmp = stack->b;
	if (tmp)
		max_val = tmp->index;
	while (tmp)
	{
		if (tmp->next && tmp->next->index < max_val)
		{
			max_val = tmp->next->index;
		}
		tmp = tmp->next;
	}
	while (stack->b && elems > 2 && stack->b->index != max_val)
	{
		f_rotate(&stack->b, 1, 1);
		print_both_stacks(stack, b_index, 0);
		
		
	}
	// printf(" least pos == %i \n\n", least_pos);
	// usleep(900000);
	// if (least_pos < stack->elements / 2)
	// {
	// 	do_rotation(get_rotation_type(1), least_pos, &stack->b);
	// }
	// else
	// {
		//do_rotation(get_rotation_type(0), least_pos, &stack->b);
		// while (least_pos != 0)
		// {
		// 	printf("put_least_elem_of_b_to_head, least pos == %i \n\n", least_pos);
		// 	usleep(1200000);
		// 	f_rotate(&stack->b, 1, 1);
		// 	print_both_stacks(stack, b_index, least_pos);
		// 	printf("put_least_elem_of_b_to_head, least pos == %i \n\n", least_pos);
		// 	least_pos--;
		// 	usleep(1200000);
		// }
	//}
}

int	return_biggest_elems_from_b(t_stack *stack, t_node *node)
{
	while (node)
	{
		if (is_one_of_three_biggest_elems(stack, node->index))
			return (1);
		node = node->next;
	}
	return (0);
}

void	sort_stack_A(t_stack *stack)
{
	int		elems_in_b;
	t_temp	node;
	int		index;

	elems_in_b = count_stack_elements(stack->b);
	index = stack->max_values[0] - 1;
	while (stack->b)
	{
		elems_in_b = count_stack_elements(stack->b);
		node.top = get_node_index_position_from_top(stack->b, index);
		node.bottom = get_node_index_position_from_bottom(stack->b, index, elems_in_b);
		do_less_rotation_moves_b(node, stack, &stack->b, index);
		f_push(&stack->b, &stack->a, 1, 1);
		print_both_stacks(stack, 0, elems_in_b);
		index--;
	}
}