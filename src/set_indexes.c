/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/19 22:51:18 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_selection(t_node *a, t_node *b);
t_node	*create_aux_stack(t_node *original);
void	set_index_to_original_stack(t_node *original, t_node *aux);
void	free_stack(t_node **head);
t_moves	*init_num_moves(void);
int		are_elems_of_current_bucket_in_a(t_stack *stack, int b_index);
void	sort_stack_A(t_stack *stack);
void	set_three_biggest_elems(t_stack *stack);
int	return_biggest_elems_from_b(t_stack *stack);

/**
 * @brief Sorts the stack in a temporal stack to sets indexes to each elem
 */
void	set_index_to_each_elem(t_stack *stacks)
{
	t_iter	iter;
	int		index;
	t_node	*next;
	t_node	*aux;
	t_node	*head;

	iter.i = 0;
	iter.j = 0;
	index = 0;
	aux = create_aux_stack(stacks->a);
	head = aux;
	while (aux->next != NULL)
	{
		next = aux->next;
		while (next != NULL)
		{
			if (aux->data > next->data)
			{
				swap_selection(aux, next);
				next->index = index;
				aux->index = index;
			}
			else
				aux->index = index;
			next = next->next;
		}
		aux = aux->next;
		index++;
	}
	aux->index = index;
	aux = head;
	set_bucket_sort_values(stacks, aux);
	set_index_to_original_stack(stacks->a, aux);
	set_three_biggest_elems(stacks);
	free_stack(&aux);
}

void	set_three_biggest_elems(t_stack *stack)
{
	int	val;
	int	i;

	val = stack->elements - 3;
	i = 0;
	while (i < 3)
	{
		stack->max_values[i] = val;
		printf (" + + + stack->max_values[%i]: %i\n", i, stack->max_values[i]);
		usleep(1200000);
		val++;
		i++;
	}
}
void	swap_selection(t_node *a, t_node *b)
{
	t_node		*val1;
	long int	data1;
	t_node		*val2;

	val1 = a;
	val2 = b;
	data1 = val1->data;
	val1->data = val2->data;
	val2->data = data1;
}

t_node	*create_aux_stack(t_node *original)
{
	t_node	*head;
	t_node	*stack;

	stack = (t_node *)malloc(sizeof(t_node));
	stack->data = original->data;
	stack->next = NULL;
	head = stack;
	original = original->next;
	while (original != NULL)
	{
		add_value_back(&stack, original->data);
		original = original->next;
	}
	return (head);
}

void	set_index_to_original_stack(t_node *original, t_node *aux)
{
	t_node	*head_a;
	t_node	*head_o;
	t_node	*aux_head;

	head_a = aux;
	head_o = original;
	while (head_a != NULL)
	{
		aux_head = head_o;
		while (aux_head != NULL)
		{
			if (head_a->data == aux_head->data)
			{
				aux_head->b_index = head_a->b_index;
				aux_head->index = head_a->index;
				aux_head->is_sorted = 0;
				break ;
			}
			aux_head = aux_head->next;
		}
		head_a = head_a->next;
	}
}

void	f_insertion_sort(t_stack *stack)
{
	t_temp		node;
	t_rotations	rotations;
	int			last_val;
	int			current_elems;
	int			b_index;
	int			curr_elems_b;

	b_index = 0;
	current_elems = count_stack_elements(stack, 0);
	while (stack->a && current_elems > 3)
	{
		while (are_elems_of_current_bucket_in_stack(stack->a, b_index) &&
			current_elems > 3)
		{
			node.top = get_node_position_from_top(stack->a, b_index);
			node.bottom = get_node_position_from_bottom(stack->a, b_index, current_elems);
			// printf("node.top position: %i\n", node.top);
			// printf("node.bottom position: %i\n", node.bottom);
			// printf("+++ b_index: %i\n", b_index);
			// usleep(1100000);
			do_less_rotation_moves_a(node, stack, &stack->a);
			print_both_stacks(stack, b_index, 0);
			// if (!is_one_of_three_biggest_elems(stack, stack->a->index))
			// {
				// if (stack->b && stack->a->index < stack->b->index)
				// {
				// 	curr_elems_b = count_stack_elements(stack, 1);
				// 	last_val = get_index_of_last_elem(stack->b);
				// 	if (stack->b && curr_elems_b >= 4 && last_val > stack->b->index && last_val > stack->b->next->index)
				// 	{
				// 		f_reverse_rotate(&stack->b, 1, 1);
				// 		f_push(&stack->a, &stack->b, 1, 2);
				// 		f_rotate(&stack->b, 1, 1);
				// 		f_rotate(&stack->b, 1, 1);
				// 	}
				// 	else
				// 	{
				// 		f_reverse_rotate(&stack->b, 1, 1);
				// 		f_push(&stack->a, &stack->b, 1, 2);
				// 		f_rotate(&stack->b, 1, 1);
				// 	}
				// }
				// else
				if (stack->a->b_index == b_index && !is_one_of_three_biggest_elems(stack, stack->a->index))
					f_push(&stack->a, &stack->b, 1, 2);
			//}
			print_both_stacks(stack, b_index,0);
			current_elems = count_stack_elements(stack, 0);
		}
		b_index++;
	}
	//f_rotate(&stack->b, 1, 1);
	if (return_biggest_elems_from_b(stack))
	{
		f_rotate(&stack->b, 1, 1);
		f_push(&stack->b, &stack->a, 1, 1);
	}
	sort_three_elems(stack, stack->a);
	sort_stack_A(stack);
	print_both_stacks(stack, b_index, 0);
}

int	return_biggest_elems_from_b(t_stack *stack)
{
	while (stack->b)
	{
		if (is_one_of_three_biggest_elems(stack, stack->b->index))
		{
			printf("---- index %i is one of biggest elems ----\n", (stack->b->index));
				usleep(1400000);
			// f_rotate(&stack->b, 1, 1);
			// f_push(&stack->b, &stack->a, 1, 1);
			return (1);
			// if (is_one_of_three_biggest_elems(stack, stack->b->index))
			// {
			// 	printf("---- index %i is one of biggest elems ----\n", (stack->b->index));
			// 	usleep(900000);
			// 	f_push(&stack->b, &stack->a, 1, 1);
			// }
		}
		stack->b = stack->b->next;
	}
	return (0);
}

void	sort_stack_A(t_stack *stack)
{
	int	elems_in_b;
	t_temp	node;
	int		index;

	elems_in_b = count_stack_elements(stack, 1);
	index = stack->max_values[0];
	while (stack->b)
	{
		elems_in_b = count_stack_elements(stack, 1);
		node.top = get_node_index_position_from_top(stack->b, index);
		node.bottom = get_node_index_position_from_bottom(stack->b, index, elems_in_b);
		// printf("index: %i\n", index);
		// printf("elems_in_b: %i\n", elems_in_b);
		// printf("node.top position: %i\n", node.top);
		// printf("node.bottom position: %i\n", node.bottom);
		// usleep(1400000);
		do_less_rotation_moves_b(node, stack, &stack->b, index);
		f_push(&stack->b, &stack->a, 1, 1);
		print_both_stacks(stack, 0, elems_in_b);
		index--;
	}
}


void	put_least_elem_of_b_to_head(t_stack *stack, int b_index)
{
	t_node	*tmp;
	int		max_val;
	int	elems;

	elems = count_stack_elements(stack, 1);
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


int	check_all_elements(t_stack *stack, int n)
{
	t_node	*current;
	int		i;

	if (n == 0)
	{
		i = 0;
		current = stack->a;
	}
	else
	{
		i = 1;
		current = stack->b;
	}
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	if (i == stack->elements)
		return (1);
	return (0);
}

int	count_stack_elements(t_stack *stack, int n)
{
	t_node	*current;
	int		i;

	if (n == 0)
	{
		i = 0;
		current = stack->a;
	}
	else
	{
		i = 0;
		current = stack->b;
	}
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	count_stack_elements_2(t_node **stack, int n)
{
	t_node	**current;
	int		i;

	if (n == 0)
	{
		i = 0;
		current = stack;
	}
	else
	{
		i = 1;
		current = stack;
	}
	while (current != NULL)
	{
		*current = (*current)->next;
		i++;
	}
	return (i);
}

t_moves	*init_num_moves(void)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	return (moves);
}
