/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/28 22:28:13 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_selection(t_node *a, t_node *b);
t_node	*create_aux_stack(t_node *original);
void	set_index_to_original_stack(t_node *original, t_node *aux);
void	free_stack(t_node **head);
int	is_last_index_less(t_node *lst, int index);
int	is_index_before_first_half(t_stack *stack, int index);
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

/**
 * TO-DO Search and save 1 element of bucket X, and compare it with another element of bucket X,
 * count which of them need less rotations and do it
 */
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
			print_both_stacks(stack, iter.i, iter.j);
			current_elems = count_stack_elements(stack, 0);
			node.top = get_node_position_from_top(stack->a, b_index);
			node.bottom = get_node_position_from_bottom(stack->a, b_index, stack->elements);
			// printf("node.top position: %i\n", node.top);
			// printf("node.bottom position: %i\n", node.bottom);
			// usleep(300000);
			// Get how many movements each one needs.
			
			// Do rotations to put elem at stack head
			do_less_rotation_moves(node, stack, b_index);
			print_both_stacks(stack, iter.i, iter.j);
			// in B move the least element to head and push A to B
			put_least_elem_of_b_to_head(stack, b_index);
			print_both_stacks(stack, iter.i, iter.j);
			f_push(&stack->a, &stack->b, 1, 2);
			print_both_stacks(stack, iter.i, iter.j);
		}
		b_index++;
	}
	iter.i = 0;
	while (stack->b)
	{
		f_push(&stack->b, &stack->a, 1, 1);
		print_both_stacks(stack, iter.i, iter.j);
		iter.i++;
	}
	print_both_stacks(stack, iter.i, iter.j);
	free(moves);
}

void	put_least_elem_of_b_to_head(t_stack *stack, int b_index)
{
	int	least_pos;

	least_pos = get_least_elem_position(stack, stack->b);
	if (least_pos < stack->elements / 2)
	{
		do_rotation(get_rotation_type(1), least_pos, &stack->b);
	}
	else
	{
		do_rotation(get_rotation_type(0), least_pos + 1, &stack->b);
	}
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
			}
			else if (next->index < tmp->index)
			{
				least_pos = pos + 1;
			}
			next = next->next;
		}
		tmp = tmp->next;
		
		pos++;
	}
	//printf("position of the least element: %i\n", least);
	//usleep(600000);
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

int	is_index_current_or_next(t_stack *stack, int which, int index)
{
	t_node	*current;

	if (which == 0)
		current = stack->a;
	else
		current = stack->b;
	if (current->index == index || current->next->index == index)
		return (1);
	return (0);
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

int	is_last_index_less(t_node *lst, int index)
{
	t_node	*tmp;

	tmp = lst;
	while (lst->next)
	{
		lst = lst->next;
	}
	if (lst->index < index)
		return (1);
	lst = tmp;
	return (0);
}

int	is_index_before_first_half(t_stack *stack, int index)
{
	t_node	*tmp;
	int		elements;
	int		i;

	i = 0;
	elements = count_stack_elements(stack, 0);
	tmp = stack->a;
	while (i <= (elements / 2))
	{
		if (tmp->index == index)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

t_moves	*init_num_moves(void)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	return (moves);
}
