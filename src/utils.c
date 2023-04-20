/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/20 21:51:02 by iostancu         ###   ########.fr       */
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
	int		i;
	t_node	**tmp;
	int		temp_bottom;
	int		elems_a;

	i = 0;
	tmp = l;
	elems_a = count_stack_elements(s->a);
	if (aux.bottom > elems_a / 2)
		temp_bottom = aux.bottom;
	else
		temp_bottom = elems_a - aux.bottom;
	if (aux.top > aux.bottom)
	{
		while (aux.bottom != 0)
		{
			f_reverse_rotate(tmp, s, 0, 0);
			aux.bottom--;
		}
	}
	else
	{
		while (aux.top != 0)
		{
			f_rotate(l, s, 0, 0);
			aux.top--;
		}
	}
	if (!is_one_of_three_biggest_elems(s, (*tmp)->index))
		return ;
	else
	{
		f_push(&s->a, &s->b, s, 2);
		f_rotate(&s->b, s, 0, 1);
	}
}

int	get_least_elem_position(t_stack *stack, t_node *lst)
{
	t_node	*tmp;
	t_node	*next;
	int		least_pos;
	int		pos;

	least_pos = 0;
	pos = 0;
	tmp = lst;
	if (tmp)
	{
		next = tmp->next;
	}
	while (tmp)
	{
		if (next)
		{
			if (tmp->index < next->index)
				least_pos = pos;
			else if (next->index < tmp->index)
				least_pos = pos + 1;
			next = next->next;
			pos++;
		}
		tmp = tmp->next;
	}
	return (least_pos);
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

int	get_node_position_from_top(t_stack *stack, t_node *lst, int b_index)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index && !is_one_of_three_biggest_elems(stack, tmp->index))
		{
			return (pos);
		}
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_node_position_from_bottom(t_stack *stack, t_node *lst, int b_index, int elems)
{
	t_node	*tmp;
	int		pos;
	int		elem_pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index && !is_one_of_three_biggest_elems(stack, tmp->index))
			elem_pos = pos;
		tmp = tmp->next;
		pos++;
	}
	return (elems - elem_pos);
}

int	get_node_index_position_from_top(t_node *lst, int index)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_node_index_position_from_bottom(t_node *lst, int i, int elems)
{
	t_node	*tmp;
	int		pos;
	int		elem_pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == i)
			elem_pos = pos;
		tmp = tmp->next;
		pos++;
	}
	return (elems - elem_pos);
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
