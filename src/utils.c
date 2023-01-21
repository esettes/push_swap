/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/01/21 23:57:01 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	do_rotation(void (*f)(t_node **, int, int), int index, t_node **lst);

int	get_node_position(t_node *lst)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	count_num_movements(t_moves *moves, t_node *lst, int elems)
{
	moves->moves_i_rotate = get_node_position(lst) - 1;
	moves->moves_i_reverse = elems - get_node_position(lst) + 1;
	moves->moves_j_rotate = get_node_position(lst) - 1;
	moves->moves_j_reverse = elems - get_node_position(lst) + 1;
}

void	*get_rotation_type(int sel)
{
	void	(*ptr)(t_node **, int, int);

	if (sel == 0)
		ptr = &f_rotate;
	else
		ptr = &f_reverse_rotate;
	return (ptr);
}

void	do_less_rotation_moves(t_moves *moves, t_node **lst, t_iter it)
{
	int	i_rot;
	int	i_rev;
	int	j_rot;
	int	j_rev;

	i_rot = moves->moves_i_rotate;
	i_rev = moves->moves_i_reverse;
	j_rot = moves->moves_j_rotate;
	j_rev = moves->moves_j_reverse;
	if ((i_rot < i_rev) && (i_rot < j_rot) && (i_rot < j_rev))
		do_rotation(get_rotation_type(0), it.i, lst);
	if ((i_rev < i_rot) && (i_rev < j_rot) && (i_rev < j_rev))
		do_rotation(get_rotation_type(1), it.i, lst);
	if ((j_rot < i_rev) && (j_rot < i_rot) && (j_rot < j_rev))
		do_rotation(get_rotation_type(0), it.j, lst);
	if ((j_rev < i_rev) && (j_rev < j_rot) && (j_rev < i_rot))
		do_rotation(get_rotation_type(1), it.j, lst);
	else
		do_rotation(get_rotation_type(0), it.i, lst);
}

void	do_rotation(void (*f)(t_node **, int, int), int index, t_node **lst)
{
	t_node	*current;

	current = (*lst);
	while (current && current->index != index)
	{
		f(lst, 1, 0);
		current = current->next;
	}
}
