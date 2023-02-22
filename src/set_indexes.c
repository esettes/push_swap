/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 21:45:53 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_selection(t_node *a, t_node *b);
t_node	*create_aux_stack(t_node *original);
void	set_index_to_original_stack(t_node *original, t_node *aux);
void	free_stack(t_node **head);
int	check_all_elements(t_stack *stack, int n);
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
				aux_head->index = head_a->index;
				break ;
			}
			aux_head = aux_head->next;
		}
		head_a = head_a->next;
	}
}

void	f_sort(t_stack *stack)
{
	t_node	*head_a;
	t_iter	iter;
	t_moves	*moves;
	int		middle;
	int		current_elems;

	moves = init_num_moves();
	iter.i = 0;
	iter.j = (stack->elements / 2) + 1;
	middle = iter.j - 1;
	head_a = stack->a;
	while (stack->a)
	{
		print_both_stacks(stack, iter.i, iter.j);
		current_elems = count_stack_elements(stack, 0);
		if (pushed_current_index(stack, &iter, middle) == 0)
		{
			count_num_movements(moves, stack->a, iter, current_elems);
			if (stack->a && stack->a->index != iter.i && stack->a->index != iter.j)
			{
				do_less_rotation_moves(stack->elements, moves, &stack->a, iter);
			}
		}
	}
	iter.i = 0;
	while (stack->b && (iter.i <= middle))
	{
		f_push(&stack->b, &stack->a, 1, 1);
		print_both_stacks(stack, iter.i, iter.j);
		iter.i++;
	}
	while (stack->b && (middle <= stack->elements))
	{
		f_push(&stack->b, &stack->a, 1, 1);
		f_rotate(&stack->a, 1, 2);
		print_both_stacks(stack, iter.i, iter.j);
		middle++;
	}
	print_both_stacks(stack, iter.i, iter.j);
	free(moves);
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
