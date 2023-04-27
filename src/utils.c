/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 23:29:05 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_less_rotation_moves_b(t_temp aux, t_stack *s, t_node **l, int index)
{
	int		i;
	t_node	**tmp;
	int		temp_bottom;
	int		elems_b;

	i = 0;
	tmp = l;
	elems_b = count_stack_elements(s->b);
	temp_bottom = elems_b - aux.bottom;
	if (aux.top > aux.bottom)
	{
		while (aux.bottom != 0)
		{
			f_reverse_rotate(l, s, 0, 1);
			aux.bottom--;
		}
	}
	else
	{
		while (aux.top != 0)
		{
			f_rotate(l, s, 0, 1);
			aux.top--;
		}
	}
}

void	do_less_rotation_moves_a(t_temp aux, t_stack *s, t_node **l)
{
	t_node	**tmp;
	int		temp_bottom;
	int		elems_a;

	tmp = l;
	elems_a = count_stack_elements(s->a);
	if (aux.bottom > elems_a / 2)
		temp_bottom = aux.bottom;
	else
		temp_bottom = elems_a - aux.bottom;
	if (aux.top > aux.bottom)
	{
		while (aux.bottom-- != 0)
			f_reverse_rotate(tmp, s, 0, 0);
	}
	else
	{
		while (aux.top-- != 0)
			f_rotate(l, s, 0, 0);
	}
	if (!is_one_of_three_biggest_elems(s, (*tmp)->index))
		return ;
	f_push(&s->a, &s->b, s, 2);
	f_rotate(&s->b, s, 0, 1);
}

int	is_one_of_three_biggest_elems(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (val == stack->max_values[i])
			return (1);
		i++;
	}
	return (0);
}

int	are_elems_of_current_bucket_in_stack(t_node *stack, int b_index)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->b_index == b_index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort_three_elems(t_stack *stack, t_node *node)
{
	t_node	*head;
	t_node	*next;
	t_node	*next_next;

	head = node;
	next = node->next;
	next_next = next->next;
	if (!is_sorted_stack(&stack->a) && stack->elements == 2)
		f_swap(&stack->a, stack, 0, 0);
	while (!is_sorted_stack(&stack->a))
	{
		if ((stack->a->index > stack->a->next->index
				&& stack->a->index < stack->a->next->next->index)
			|| (stack->a->index < stack->a->next->index
				&& stack->a->index < stack->a->next->next->index))
			f_swap(&stack->a, stack, 0, 0);
		if (stack->a->index > stack->a->next->index
			&& stack->a->index > stack->a->next->next->index)
			f_rotate(&stack->a, stack, 0, 0);
		if (stack->a->index < stack->a->next->index
			&& stack->a->index > stack->a->next->next->index)
			f_reverse_rotate(&stack->a, stack, 0, 0);
	}
}
