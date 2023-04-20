/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:15:13 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/20 21:15:22 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_elems_except_last_three(t_stack *stack)
{
	while (count_stack_elements(stack->a) > 3)
	{
		
		if (stack->a->index < (stack->elements - 2))
		{
			f_push(&stack->a, &stack->b, 1, 2);
			print_both_stacks(stack, 0, 0);
		}
		else
		{
			f_rotate(&stack->a, 1, 0);
			print_both_stacks(stack, 0, 0);
		}
		// printf("stack elems -------- %i \n ", count_stack_elements(stack, 0));
		// usleep(750000);
		stack->a = stack->a->next;
	}
}