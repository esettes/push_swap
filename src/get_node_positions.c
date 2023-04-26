/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:08:13 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/26 17:27:27 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_position_from_top(t_stack *stack, t_node *lst, int b_index)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index
			&& !is_one_of_three_biggest_elems(stack, tmp->index))
		{
			return (pos);
		}
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_node_position_from_bottom(t_stack *stack, t_node *lst, int b_index,
	int elems)
{
	t_node	*tmp;
	int		pos;
	int		elem_pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index && !is_one_of_three_biggest_elems(stack,
				tmp->index))
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
