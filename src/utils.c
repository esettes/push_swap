/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/13 21:31:27 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	do_rotation(void (*f)(t_node **, int, int), int index, t_node **lst);

int	get_node_position(t_node *lst, int i)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (i == tmp->index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	count_num_movements(t_moves *moves, t_node *lst, t_iter i, int elems)
{
	int	position_i;
	int	position_j;

	position_i = get_node_position(lst, i.i);
	position_j = get_node_position(lst, i.j);
	moves->moves_i_rotate = position_i - 1;
	moves->moves_i_reverse = elems - position_i + 1;
	moves->moves_j_rotate = position_j - 1;
	moves->moves_j_reverse = elems - position_j + 1;
	printf("Elem postion (i): %d\n", position_i);
	printf("Elem postion (j): %d\n", position_j);
	printf("moves_i_rotate: %d\n", moves->moves_i_rotate);
	printf("moves_i_reverse: %d\n", moves->moves_i_reverse);
	printf("moves_j_rotate: %d\n", moves->moves_j_rotate);
	printf("moves_j_reverse: %d\n", moves->moves_j_reverse);
	//usleep(250000);
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
	{
		do_rotation(get_rotation_type(0), it.i, lst);
	}
	else if ((i_rev < i_rot) && (i_rev < j_rot) && (i_rev < j_rev))
	{
		do_rotation(get_rotation_type(1), it.i, lst);
		}
	else if ((j_rot < i_rev) && (j_rot < i_rot) && (j_rot < j_rev))
	{
		do_rotation(get_rotation_type(0), it.j, lst);
		}
	else if ((j_rev < i_rev) && (j_rev < j_rot) && (j_rev < i_rot))
	{
		do_rotation(get_rotation_type(1), it.j, lst);
		}
	else
		//{
			//if (i_rot == j_rot && i_rot < i_rev)
				do_rotation(get_rotation_type(0), it.i, lst);
			//else
			//	do_rotation(get_rotation_type(1), it.j, lst);
		//}
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
