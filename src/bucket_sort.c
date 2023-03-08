/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/08 23:33:31 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	search_elems_of_current_bucket_index(t_stack *stack, int i);
void	push_current_bucket_sorted(t_stack *stack, int *index);
int		is_current_bucket_sorted(t_node *stack, int index);
int		get_bucket_index_of_last_elem(t_node *stack);
int		are_all_buckets_sorted(t_stack *stack);
t_node	*get_last_elem_of_list(t_node *stack);

void	f_bucket_sort(t_stack *stack)
{
	int		bucket_i;
	int		previous_bucket;

	bucket_i = 1;
	previous_bucket = 0;
	while (stack->a)
	{
		
		if(check_all_elements(stack, 0) && is_sorted_stack(&stack->a))
			break ;
		search_elems_of_current_bucket_index(stack, bucket_i);
		previous_bucket = bucket_i;
		push_current_bucket_sorted(stack, &bucket_i);
		// if all buckets are in order, exit
		// if (are_all_buckets_sorted(stack))
		// {
		// 	printf(" +++++ All buckets sorted !! +++++\n");
		// 	return ;
		// }
	}
}

int	are_all_buckets_sorted(t_stack *stack)
{
	t_node	*next;

	while (stack->a)
	{
		next = stack->a->next;
		if (next && (stack->a->b_index > next->b_index))
			return (0);
		stack->a = stack->a->next;
	}
	return (1);
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

void	search_elems_of_current_bucket_index(t_stack *stack, int i)
{
	t_node	*aux;
	// keep if this loop if the current bucket is not shorted (?)
	
	//while is not current b_index, push to B and rotate B
	while (stack->a->b_index != i)
	{
		f_push(&stack->a, &stack->b, 1, 2);
		f_rotate(&stack->b, 1, 1);
		print_both_stacks(stack, i, 0);
	}
	if (stack->a->b_index == i)
	{
		aux = get_last_elem_of_list(stack->a);
		if (aux->b_index == i)
		{
			if (stack->a->data > aux->data)
			{
				f_rotate(&stack->a, 1, 0);
			}
			else if (stack->a->data < aux->data)
			{
				f_reverse_rotate(&stack->a, 1, 0);
				f_push(&stack->a, &stack->b, 1, 2);
				f_rotate(&stack->a, 1, 0);
			}
			if (stack->b->index == aux->index + 1)
			{
				f_push(&stack->b, &stack->a, 1, 1);
				f_rotate(&stack->a, 1, 0);
			}
			else if (stack->b->next->index == aux->index + 1)
			{
				f_swap(&stack->b, 1, 0);
				f_push(&stack->b, &stack->a, 1, 1);
				f_rotate(&stack->a, 1, 0);
			}
		}
	}
	// if it have current b_index then
	//		if its bigger than the last elem of the list, rotate A
	//		if its smaller than the last elem, reverse rotate, push to B and rotate A
	//		check if in B is the consecutive element, if its, push to A and rotate A
}


/**
 * @brief If current bucket index is sorted, push all elements to stack A.
 * Later, adds +1 to current bucket index.
 */
void	push_current_bucket_sorted(t_stack *stack, int *index)
{
	if (is_reverse_sorted(&stack->b) || stack->bucket_range == 1)
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

int	is_current_bucket_sorted(t_node *stack, int index)
{
	t_node	*next;

	while (stack && stack->b_index != index)
	{
		stack = stack->next;
	}
	next = stack->next;
	while (next && stack->b_index == index)// && next->b_index == index)
	{
		if (stack->data > next->data)
			return (0);
		stack = next;
		next = stack->next;
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

t_node	*get_last_elem_of_list(t_node *stack)
{
	while (stack)
	{
		stack = stack->next;
	}
	return (stack);
}

