/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/08 20:38:04 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	search_current_index_value(t_stack *stack, int i);
void	push_current_bucket_sorted(t_stack *stack, int *index);
int		is_current_bucket_sorted(t_node **stack, int index);
int		get_bucket_index_of_last_elem(t_node *stack);

void	f_bucket_sort(t_stack *stack)
{
	int		bucket_i;

	bucket_i = 0;
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
	while (!is_current_bucket_sorted(stack->a, i))
	{
		if (stack->a->b_index != i)
		{
			f_reverse_rotate(stack->a, 1, 1);
			print_both_stacks(stack, i, 0);
		}
		// if (stack->a->b_index == i)
		// {
		// 	f_
		// }
	}
}

/**
 * @brief If current bucket index is sorted, push all elements to stack A.
 * Later, adds +1 to current bucket index.
 */
void	push_current_bucket_sorted(t_stack *stack, int *index)
{
	if (is_reverse_sorted(&stack->b))
	{
		// if (index == 0)
		// {
		// 	while (stack->a->b_index != *index)
		// 		f_reverse_rotate(&stack->a, 1, 1);
		// }
		if (*index > 0)
		{
			// * * * * * * *
			// search the previous index and move it at the end of the list.
			// Then push and reverse rotate stack 
			// * * * * * * * 
			while (stack->a->b_index != *index - 1)
				f_reverse_rotate(&stack->a, 1, 1);
			
		}
		while (stack->b)
		{
			f_push(&stack->b, &stack->a, 1, 1);
			f_reverse_rotate(&stack->a, 1, 1);
			print_both_stacks(stack, *index, 0);
		}
	}
	*index += 1;
}

int	is_current_bucket_sorted(t_node **stack, int index)
{
	t_node	*next;

	
	while (stack && *(stack->b) != index)
	{
		stack = stack->next;
		stack->data
	}
	next = stack->a->next;
	while (next && stack->a->b_index == index)
	{
		if (stack->a->data > next->data)
			return (0);
		stack->a = next;
		next = stack->a->next;
	}
	return (1);
}

int	get_bucket_index_of_last_elem(t_node *stack)
{
	while (stack)
	{
		stack = stack->next;
	}
	return (stack->b_index);
}
