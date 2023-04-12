/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/12 22:26:57 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	search_elems_of_current_b_index(t_stack *stack, int i, t_node *aux);
void	push_current_bucket_sorted(t_stack *stack, int *index);
//int		is_current_bucket_sorted(t_stack *stack, t_node *lst, int index);
int		get_bucket_index_of_last_elem(t_node *stack);
int		are_all_buckets_sorted(t_stack *stack);
t_node	*get_last_elem_of_list(t_node *stack);
int		is_elem_of_current_bucket_index_here(t_node *lst, int i);
void	push_current_b_index(t_stack *stack, int i);

/**
 * TO-DO
 * Check if bucket is naturally sorted in stack A before move elements to stack B
 */
void	f_bucket_sort(t_stack *stack)
{
	int		bucket_i;
	int		previous_bucket;
	t_node	*aux;

	bucket_i = 0;
	previous_bucket = 0;
	aux = malloc(sizeof(t_node));
	while (stack->a)
	{
		
		if(check_all_elements(stack, 0) && is_sorted_stack(&stack->a))
		{
			free(aux);
			break ;
		}
		previous_bucket = bucket_i;
		if (stack->b_elems[bucket_i].is_sorted != 0)
		{
			bucket_i++;
		}
		//push_current_b_index(stack, bucket_i);
		//push_current_bucket_sorted(stack, &bucket_i);
		// if all buckets are in order, exit
		// if (are_all_buckets_sorted(stack))
		// {
		// 	printf(" +++++ All buckets sorted !! +++++\n");
		// 	return ;
		// }
	}
	free(aux);
}

void	push_all_elems_except_last_three(t_stack *stack)
{
	while (count_stack_elements_2(&stack->a, 0) > 3)
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

void	push_current_b_index(t_stack *stack, int i)
{
	// if there's any elem of current b_index in stack A, then all of them are in B
	// push elems to A, checking their order
	if (!is_elem_of_current_bucket_index_here(stack->a, i))
	{
		while (is_elem_of_current_bucket_index_here(stack->b, i))
		{
			if (!stack->a->data || stack->b->data > stack->a->data)
			{
				f_push(&stack->b, &stack->a, 1, 1);
				f_reverse_rotate(&stack->a, 1, 1);
			}
			//if (stack->b->data < )
		}
	}
}

int	is_elem_of_current_bucket_index_here(t_node *lst, int i)
{
	while (lst)
	{
		if (lst->b_index == i)
			return (1);
		lst = lst->next;
	}
	return (0);
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

int	get_bucket_index_of_last_elem(t_node *stack)
{
	while (stack)
	{
		stack = stack->next;
	}
	return (stack->b_index);
}

int	get_index_of_last_elem(t_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->index);
}

t_node	*get_last_elem_of_list(t_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
