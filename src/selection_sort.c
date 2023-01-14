/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/01/15 00:34:08 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_selection(t_node *a, t_node *b);
t_node	*create_aux_stack(t_node *original);
void	set_index_to_original_stack(t_node *original, t_node *aux);
void	free_stack(t_node **head);
int	check_all_elements(t_stack *stack);

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
	//printf("\nIndexing....\n");
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
	// printf("\nPrint....\n");
	// while (aux != NULL)
	// {
	// 	printf("%d \t %d\n",aux->data, aux->index);
	// 	aux = aux->next;
	// }
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
		add_back(stack, original->data);
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
	// head_o = original;
	// printf("\n\n* * Set index to original * * \n");
	// while (head_o != NULL)
	// {
	// 	printf("%d \t %d\n",head_o->data, head_o->index);
	// 	head_o = head_o->next;
	// }
}

void	f_sort(t_stack *stack)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*next_a;
	t_node	*next_b;

	// while is not sorted
	while (!is_sorted_arg(stack->a) && !check_all_elements(stack))
	{
		head_a = stack->a;
		head_b = stack->b;
		next_a = head_a->next;
		while (head_a && next_a)
		{
			next_a = head_a->next;
			//while (next_a)
			//{
				if (head_a->index > next_a->index)
				{
					f_reverse_rotate(&stack->a, 1, 1);
					f_push(&stack->a, &stack->b, 1, 2);
					//stack->a = head_a;
					//f_reverse_rotate(head_a, 1, 1);
				}
				else if (head_a->index < next_a->index)
				{
					f_push(&stack->a, &stack->b, 1, 2);
					//f_reverse_rotate(&stack->a, 1, 1);
				}
				
				printf("* * *\n");
				print_both_stacks(stack);
				if (head_b && head_a->index > head_b->index)
					f_push(&stack->b, &stack->a, 1, 1);
				else if (head_b && head_a->index < head_b->index)
					f_push(&stack->a, &stack->b, 1, 1);
				
				next_a = next_a->next;
				
			//}
			head_a = head_a->next;
		}
		printf("exit ********************\n");
	}
}

int	check_all_elements(t_stack *stack)
{
	t_node *current;
	int		i;

	current = stack->a;
	i = 0;
	printf("elements original: %d\n", stack->elements);
	while (current->next != NULL)
	{
		current = current->next;
		i++;
		printf("elements: %d\n", i);
	}
	printf("elements: %d\n", i);
	if (i == stack->elements)
	{
		printf("elements: %d\n", i);
		return (1);
	}
	return (0);
}