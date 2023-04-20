/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:15:13 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/20 21:50:22 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_elems_except_last_three(t_stack *stack)
{
	while (count_stack_elements(stack->a) > 3)
	{
		if (stack->a->index < (stack->elements - 2))
		{
			f_push(&stack->a, &stack->b, stack, 2);
		}
		else
		{
			f_rotate(&stack->a, stack, 0, 0);
		}
		stack->a = stack->a->next;
	}
}
