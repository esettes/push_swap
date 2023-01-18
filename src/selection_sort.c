/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/01/18 23:55:34 by iostancu         ###   ########.fr       */
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

void	selection_sort(t_stack *stacks)
{
	t_iter	iter;
	int		index;
	t_node	*next;
	t_node	*aux;
	t_node *head;

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
	int		i;
	int		j;
	int		middle;

	while (!is_sorted_arg(&stack->a) || !check_all_elements(stack, 0))
	{
		i = 0;
		j = stack->elements / 2;
		middle = j;
		head_a = stack->a;
		
		while (i <= stack->elements && stack->a)
		{
			if (j <= stack->elements)
			{
				if (stack->a && stack->a->index == j)
				{
					f_push(&stack->a, &stack->b, 1, 2);
					f_rotate(&stack->b, 1, 1);
					j++;
				}
				if (stack->a && stack->a->next && stack->a->next->index == j)
				{
					f_swap(&stack->a, 0, 0);
					f_push(&stack->a, &stack->b, 1, 2);
					f_rotate(&stack->b, 1, 1);
					j++;
				}
				printf("j: %i\n", j);
				print_both_stacks(stack);
			}
			if (stack->a && stack->a->index == i)
			{
				f_push(&stack->a, &stack->b, 1, 2);
				i++;
			}
			else if (stack->a && stack->a->next && stack->a->next->index == i)
			{
				f_swap(&stack->a, 0, 0);
				f_push(&stack->a, &stack->b, 1, 2);
				i++;
			}
			else
			{
				if (stack->a)
				{
					if (!is_index_before_first_half(stack, i))
					{
						while (stack->a->index != i)
							f_reverse_rotate(&stack->a, 1, 0);
					}
					else
					{
						while (stack->a->index != i)
							f_rotate(&stack->a, 1, 0);
					}
				}
			}
			//usleep(200000);
			print_both_stacks(stack);
		}
		if (!stack->a)
			break ;
	}
	i = 0;
	while (stack->b && (i < middle))
	{
		f_push(&stack->b, &stack->a, 1, 1);
	}
	while (stack->b && (middle <= stack->elements))
	{
		f_push(&stack->b, &stack->a, 1, 1);
		f_rotate(&stack->a, 1, 2);
		middle++;
	}
	//f_push(&stack->b, &stack->a, 1, 1);
	//print_both_stacks(stack);
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
		if (stack->a->index == index)
		{
			stack->a = tmp;
			return (1);
		}
		stack->a = stack->a->next;
		i++;
	}
	stack->a = tmp;
	return (0);
}
