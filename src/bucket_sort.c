/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/14 18:50:57 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	search_elems_of_current_b_index(t_stack *stack, int i, t_node *aux);
void	push_current_bucket_sorted(t_stack *stack, int *index);
int		is_current_bucket_sorted(t_stack *stack, t_node *lst, int index);
int		get_bucket_index_of_last_elem(t_node *stack);
int		get_index_of_last_elem(t_node *stack);
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
		search_elems_of_current_b_index(stack, bucket_i, aux);
		previous_bucket = bucket_i;
		//printf("*** checking sorted bucket in MAIN BUCKET FUNCTION... \n");
		//printf("*** stack->b_elems[%i].is_sorted... %i \n", stack->b_elems[bucket_i].is_sorted);
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

void	search_elems_of_current_b_index(t_stack *stack, int i, t_node *aux)
{
	// keep if this loop if the current bucket is not shorted (?)
	if (is_current_bucket_sorted(stack, stack->a, i))
			return ;
	//while is not current b_index, push to B and rotate B
	/*
	* * * * * if its an element of a previous index, dont move it !! * * * * * * * *
	*/
	while (stack->a->b_index != i)
	{
		f_push(&stack->a, &stack->b, 1, 2);
		f_rotate(&stack->b, 1, 1);
		print_both_stacks(stack, i, 0);
	}
	if (stack->a->b_index == i)
	{
		printf("*** checking sorted bucket in SEARCH ELEMS FOR EACH... \n");
		usleep(450000);
		if (is_current_bucket_sorted(stack, stack->a, i))
			return ;
		aux = get_last_elem_of_list(stack->a);
		// aux_b_index = get_bucket_index_of_last_elem(stack->a);
		// aux_index = get_index_of_last_elem(stack->a);
		if (aux->b_index == i)
		{
			if (stack->a->data > aux->data)
			{
				f_rotate(&stack->a, 1, 0);
			}
			else if (stack->a->data < aux->data)
			{
				f_reverse_rotate(&stack->a, 1, 1);
				f_push(&stack->a, &stack->b, 1, 2);
				f_rotate(&stack->a, 1, 0);
			}
			print_both_stacks(stack, i, 0);
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
			print_both_stacks(stack, i, 0);
		}
		if (aux->b_index != i)
		{
			f_reverse_rotate(&stack->a, 1, 1);
			print_both_stacks(stack, i, 0);
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

int	is_current_bucket_sorted(t_stack *stack, t_node *lst, int index)
{
	t_node	*next;
	int		count;

	count = 1;
	while (lst && lst->b_index != index)
	{
		lst = lst->next;
	}

		// printf("HEYYYY \n");
		// usleep(450000);
	next = lst->next;
	while (next && lst->b_index == index)// && next->b_index == index)
	{
		if (lst->data > next->data)
			return (0);
		lst = next;
		next = lst->next;
		count++;
	}
	if (count == stack->b_elems[index].num_elems)
	{
		printf(".´·`... Bucket <%i> elements: %i, cunted: %i ....´·`. \n", index, stack->b_elems[index].num_elems, count);
		stack->b_elems[index].is_sorted = 1;
		return (1);
	}
	return (0);
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
	while (stack)
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

