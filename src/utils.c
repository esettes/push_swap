/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/28 22:44:42 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	if (aux.bottom > (stack->elements / 2))
	{
		aux.bottom = stack->elements - aux.bottom;
		//printf(" aux.bottom == %i \n\n", aux.bottom);
		do_rotation(get_rotation_type(0), aux.bottom, &stack->a);
		print_both_stacks(stack, 0, 0);
		// printf(" ELEMENTS == %i \n\n", stack->elements);
		// printf(" ELEMENTS / 2 == %i \n\n", stack->elements / 2);
		// usleep(900000);
		
	}
	else
	{
		printf(" aux.top == %i \n\n", aux.top);
		usleep(900000);
		do_rotation(get_rotation_type(1), aux.top, &stack->a);
		print_both_stacks(stack, 0, 0);
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
	t_bucket	*tmp_bucket;
	int		pos;

	pos = 0;
	tmp = stack->b;
	tmp_bucket = stack->b_elems;
	if (stack->b_elems[b_index].num_elems == 1)
	{
		return (1);
	}
	while (tmp)
	{
		if (tmp->b_index == b_index)
		{
			if (stack->b_elems[b_index].num_elems == 1)
				return (1);
			if (tmp->next && tmp->index < tmp->next->index)
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

void	do_rotation(void (*f)(t_node **, int, int), int pos, t_node **lst)
{
	int	i;

	i = pos;
	if (!*lst)
		return ;
	while (lst && i != 0)
	{
		f(lst, 1, 0);
		i--;
	}
}
