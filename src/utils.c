/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/23 23:23:27 by iostancu         ###   ########.fr       */
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
	int	temp_multiply;

	temp_multiply = 1;
	if (i.j == elems)
		temp_multiply += 90000;
	position_i = get_node_position(lst, i.i) - 1;
	position_j = get_node_position(lst, i.j);
	moves->moves_i_rotate = position_i + 1;
	moves->moves_i_reverse = elems - position_i + 1;
	moves->moves_j_rotate = position_j + temp_multiply;
	moves->moves_j_reverse = elems - position_j + temp_multiply;
	/*printf("Elem postion (i): %d\n", position_i);
	printf("Elem postion (j): %d\n", position_j);
	printf("moves_i_rotate: %d\n", moves->moves_i_rotate);
	printf("moves_i_reverse: %d\n", moves->moves_i_reverse);
	printf("moves_j_rotate: %d\n", moves->moves_j_rotate);
	printf("moves_j_reverse: %d\n", moves->moves_j_reverse);
	
	usleep(500000);*/
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

void	do_less_rotation_moves(t_temp_node aux, t_stack *stack, int b_index)
{
	int	i;

	i = 0;
	if (aux.top < aux.bottom && aux.top < (stack->elements / 2))
	{
		// while (aux.top != 0)
		// {
			do_rotation(get_rotation_type(1), b_index, &stack->a);
		//	aux.top--;
		//}
	}
	else
	{
		// while (aux.bottom != (stack->elements - 1))
		// {
			do_rotation(get_rotation_type(0), b_index, &stack->a);
		//	aux.bottom++;
		//}
		//do_rotation(get_rotation_type(0), b_index, &stack->a);
	}
}

void	push_or_move_stack_B(t_stack *stack)
{
	while (stack->b->index > stack->a->index)
	{
		f_rotate(&stack->b, 1, 1);
	}
	f_push(&stack->a, &stack->b, 1, 2);
}

int	is_current_bucket_sorted(t_stack *stack, int b_index)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = stack->b;
	while (tmp)
	{
		if (tmp->b_index == b_index)
		{
			if (tmp->index < tmp->next->index)
				return (0);
		}
		tmp = tmp->next;
	}
	tmp = stack->a;
	while (tmp)
	{
		if (tmp->b_index == b_index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void	do_less_rotation_moves(int elems, t_moves *moves, t_node **lst, t_iter it)
// {
// 	int	i_rot;
// 	int	i_rev;
// 	int	j_rot;
// 	int	j_rev;

// 	i_rot = moves->moves_i_rotate;
// 	i_rev = moves->moves_i_reverse;
// 	j_rot = moves->moves_j_rotate;
// 	j_rev = moves->moves_j_reverse;
// 	if (i_rot < i_rev)
// 	{
// 		do_rotation(get_rotation_type(0), it.i, lst);
// 	}
// 	else
// 	{
// 		do_rotation(get_rotation_type(1), it.i, lst);
// 	}
// }

void	do_rotation(void (*f)(t_node **, int, int), int index, t_node **lst)
{
	t_node	*current;

	current = (*lst);
	while (lst && (*lst)->b_index != index)
	{
		f(lst, 1, 0);
	}
}
