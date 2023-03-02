/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/02 17:09:01 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	search_current_index_value(t_stack *stack, int i);
void	push_current_bucket_sorted(t_stack *stack, int *index);

void	f_bucket_sort(t_stack *stack)
{
	int		bucket_i;

	bucket_i = 0;
	// continuing sorting while stack is not sorted and there aren't all elements
	while (stack->a)
	{
		
		if(check_all_elements(stack, 0) && is_sorted_stack(&stack->a))
			break ;
		search_current_index_value(stack, bucket_i);
		push_current_bucket_sorted(stack, &bucket_i);
	}
}

void	sort_current_bucket(t_stack *stack, int i)
{
	
}

int	is_current_bucket_in_current_stack(t_node *stack, int index)
{
	while (stack)
	{
		if (stack->b_index == index)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	search_current_index_value(t_stack *stack, int i)
{
	while (is_current_bucket_in_current_stack(stack->a, i))
	{
		if (stack->a && stack->a->b_index == i)
		{
			if (stack->b && stack->a->data < stack->b->data)
			{
				f_push(&stack->a, &stack->b, 1, 2);
				f_swap(&stack->b, 1, 0);
				stack->b->is_sorted = 1;
				print_both_stacks(stack, i, 0);
			}
			else
			{
				f_push(&stack->a, &stack->b, 1, 2);
				stack->b->is_sorted = 1;
				print_both_stacks(stack, i, 0);
			}
		}
		else
		{
			if (stack->a->is_sorted == 1)
			{
				while (stack->a->b_index != i)
					f_reverse_rotate(&stack->a, 1, 0);
			}
			else
			{
				while (stack->a->b_index != i)
					f_rotate(&stack->a, 1, 0);
			}
			print_both_stacks(stack, i, 0);
		}
	}
}

// /**
//  * @return Bucket index that I'm currently loop.
//  */
// int	bucket_index_loop()
// {
	
// }

/**
 * @brief If current bucket index is sorted, push all elements to stack A.
 * Later, adds +1 to current bucket index.
 */
void	push_current_bucket_sorted(t_stack *stack, int *index)
{
	if (is_reverse_sorted(&stack->b))
	{
		while (stack->b)
		{
			f_push(&stack->b, &stack->a, 1, 1);
			print_both_stacks(stack, *index, 0);
		}
	}
	*index += 1;
}
