/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:04:07 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/20 23:17:49 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_last_elem(t_node *stack);

void	f_insertion_sort(t_stack *stack)
{
	t_temp	node;
	int		last_val;
	int		current_elems;
	int		b_index;
	int		curr_elems_b;

	b_index = 0;
	current_elems = count_stack_elements(stack->a);
	while (stack->a && current_elems > 3)
	{
		while (are_elems_of_current_bucket_in_stack(stack->a, b_index) &&
			current_elems > 3)
		{
			node.top = get_node_position_from_top(stack, stack->a, b_index);
			node.bottom = get_node_position_from_bottom(stack, stack->a, b_index, current_elems);
			// ft_putendl_fd(RESET_, "\n", 1);
			// printf("node.top position: %i\n", node.top);
			// printf("node.bottom position: %i\n", node.bottom);
			// printf("+++ b_index: %i\n\n", b_index);
			// usleep(50000);
			do_less_rotation_moves_a(node, stack, &stack->a);
			print_both_stacks(stack);
			// if (!is_one_of_three_biggest_elems(stack, stack->a->index))
			// {
			// if (stack->b && stack->a->index < stack->b->index)
			// {
			// 	curr_elems_b = count_stack_elements(stack->b);
			// 	last_val = get_index_of_last_elem(stack->b);
			// 	if (stack->b && curr_elems_b >= 4 && last_val > stack->b->index && last_val > stack->b->next->index)
			// 	{
			// 		f_reverse_rotate(&stack->b, stack, 0, 1);
			// 		f_push(&stack->a, &stack->b, stack, 2);
			// 		f_rotate(&stack->b, stack, 0, 1);
			// 		f_rotate(&stack->b, stack, 0, 1);
			// 	}
			// 	else
			// 	{
			// 		f_rotate(&stack->b, stack, 0, 1);
			// 		f_push(&stack->a, &stack->b, stack, 2);
			// 		f_reverse_rotate(&stack->b, stack, 0, 1);
			// 	}
			// }
			// else
				f_push(&stack->a, &stack->b, stack, 2);
			current_elems = count_stack_elements(stack->a);
		}
		b_index++;
	}
	if (return_biggest_elems_from_b(stack, stack->b))
	{
		f_reverse_rotate(&stack->b, stack, 0, 1);
		f_push(&stack->b, &stack->a, stack, 1);
	}
	// ft_putendl_fd(BLUE_, "\n\t---- going to sort three elems ----", 1);
	// usleep(800000);
	sort_three_elems(stack, stack->a);
	// ft_putendl_fd(YELLOW_, "\n\t---- finished sort three elems ----", 1);
	// ft_putendl_fd(BLUE_, "\n\t---- going to sort stack A ----", 1);
	// usleep(800000);
	sort_stack_A(stack);
	// ft_putendl_fd(GREEN_, "\n\t---- finished sort stack A ----", 1);
	// usleep(800000);
}

int	get_index_of_last_elem(t_node *stack)
{
	while (stack && stack->next)
	{
		stack = stack->next;
	}
	return (stack->index);
}
