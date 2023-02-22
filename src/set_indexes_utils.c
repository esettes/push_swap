/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:39:35 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 17:39:36 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pushed_current_index(t_stack *stack, t_iter *iter, int middle)
{
	int	is_pushed;

	is_pushed = 0;
	if (stack->a && stack->a->index == iter->i && iter->i <= middle)
	{
		f_push(&stack->a, &stack->b, 1, 2);
		print_both_stacks(stack, iter->i, iter->j);
		iter->i++;
		is_pushed = 1;
	}
	if (stack->a && stack->a->index == iter->j && iter->j <= stack->elements)
	{
		f_push(&stack->a, &stack->b, 1, 2);
		f_rotate(&stack->b, 1, 1);
		print_both_stacks(stack, iter->i, iter->j);
		iter->j++;
		is_pushed = 1;
	}
	return (is_pushed);
}

// While some of the vars of t_moves is not 0 (or -1), do the needed rotations rotation
void	do_rotations()
{
	
	
}
