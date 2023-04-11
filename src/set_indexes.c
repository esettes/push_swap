/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/11 21:20:54 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_selection(t_node *a, t_node *b);
t_node	*create_aux_stack(t_node *original);
void	set_index_to_original_stack(t_node *original, t_node *aux);
void	free_stack(t_node **head);
t_moves	*init_num_moves(void);

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
	free_stack(&aux);
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
	t_node		*head_a;
	t_iter		iter;
	t_moves		*moves;
	t_temp_node	node;
	int			middle;
	int			current_elems;
	int			b_index;

	b_index = 0;
	moves = init_num_moves();
	iter.i = 0;
	iter.j = (stack->elements / 2) + 1;
	middle = iter.j - 1;
	head_a = stack->a;
	while (stack->a)
	{
		while (!is_current_bucket_sorted(stack, b_index))
		{
			print_both_stacks(stack, b_index, iter.j);
			current_elems = count_stack_elements(stack, 0);
			node.top = get_node_position_from_top(stack->a, b_index);
			node.bottom = get_node_position_from_bottom(stack->a, b_index, stack->elements);
			printf("node.top position: %i\n", node.top);
			printf("node.bottom position: %i\n", node.bottom);
			printf("+++ b_index: %i\n", b_index);
			usleep(1100000);
			// Get how many movements each one needs.
			
			// Do rotations to put elem at stack head
			do_less_rotation_moves(node, stack, b_index);
			print_both_stacks(stack, b_index, iter.j);
			// in B move the least element to head and push A to B
			put_least_elem_of_b_to_head(stack, b_index);
			print_both_stacks(stack, b_index, iter.j);
			f_push(&stack->a, &stack->b, 1, 2);
			put_least_elem_of_b_to_head(stack, b_index);
			print_both_stacks(stack, b_index, iter.j);
		}
		b_index++;
	}
	iter.i = 0;
	while (stack->b)
	{
		f_push(&stack->b, &stack->a, 1, 1);
		print_both_stacks(stack, b_index, iter.j);
		iter.i++;
	}
	print_both_stacks(stack, b_index, iter.j);
	free(moves);
}

void	put_least_elem_of_b_to_head(t_stack *stack, int b_index)
{
	int	least_pos;
	int	elems;

	//least_pos = get_least_elem_position(stack, stack->b);
	elems = count_stack_elements(stack, 1);
	while (stack->b && elems > 2 && stack->b->index != stack->min_val)
	{
		f_rotate(&stack->b, 1, 1);
		print_both_stacks(stack, b_index, least_pos);
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

int	get_least_elem_position(t_stack *stack, t_node *lst)
{
	t_node	*tmp;
	t_node	*next;
	int		least;
	int		least_pos;
	int		pos;

	least_pos = 0;
	pos = 0;
	tmp = lst;
	if (tmp)
	{
		least = tmp->index;
		next = tmp->next;
	}
	while (tmp)
	{
		if (next)
		{
			if (tmp->index < next->index)
			{
				least_pos = pos;
				printf("lower data-> %i \n\n", tmp->index);
				usleep(1200000);
			}
			else if (next->index < tmp->index)
			{
				least_pos = pos + 1;
				printf("lower data-> %i \n\n", tmp->index);
				usleep(1200000);
			}
			next = next->next;
			pos++;
		}
		tmp = tmp->next;
		
		
	}
	return (least_pos);
}

int	get_node_position_from_top(t_node *lst, int b_index)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_node_position_from_bottom(t_node *lst, int b_index, int elems)
{
	t_node	*tmp;
	int		pos;
	int		elem_pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index)
			elem_pos = pos;
		tmp = tmp->next;
		pos++;
	}
	return (elem_pos);
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
		i = 1;
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
