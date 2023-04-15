/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/14 21:33:38 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*get_rotation_type(int sel)
{
	void	(*ptr)(t_node **, int, int);

	if (sel == 0)
		ptr = &f_rotate;
	else
		ptr = &f_reverse_rotate;
	return (ptr);
}

void	do_less_rotation_moves(t_temp aux, t_stack *s, t_node **l, int index)
{
	int	i;
	int	temp_bottom;
	int	current_elems;
	int	stack_type;

	i = 0;
	if (index > 0)
	{
		current_elems = count_stack_elements(s, 1);
		stack_type = 1;
	}
	else
	{
		current_elems = count_stack_elements(s, 0);
		stack_type = 0;
	}
	temp_bottom = current_elems - aux.bottom;
	if (aux.top < temp_bottom)
	{
		while (aux.top != 0)
		{
			f_rotate(l, 1, stack_type);
			print_both_stacks(s, 0, 0);
			aux.top--;
		}
	}
	else
	{
		
		// do_rotation(get_rotation_type(1), temp_bottom, &stack->a);
		// print_both_stacks(stack, 0, 0);
		while (temp_bottom != 0)
		{
			f_reverse_rotate(l, 1, stack_type);
			// printf("temp_bottom position: %i\n", temp_bottom);
			// usleep(1000000);
			print_both_stacks(s, 0, 0);
			temp_bottom--;
		}
	}
}


int	get_least_elem_position(t_stack *stack, t_node *lst)
{
	t_node	*tmp;
	t_node	*next;
	int		least;
	int		least_pos;
	int		pos;

	least_pos = 0;
	pos = 0;
	tmp = lst;
	if (tmp)
	{
		least = tmp->index;
		next = tmp->next;
	}
	while (tmp)
	{
		if (next)
		{
			if (tmp->index < next->index)
			{
				least_pos = pos;
				// printf("lower data-> %i \n\n", tmp->index);
				// usleep(1200000);
			}
			else if (next->index < tmp->index)
			{
				least_pos = pos + 1;
				// printf("lower data-> %i \n\n", tmp->index);
				// usleep(1200000);
			}
			next = next->next;
			pos++;
		}
		tmp = tmp->next;
		
		
	}
	return (least_pos);
}

int	get_node_position_from_top(t_node *lst, int b_index)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

int	get_node_position_from_bottom(t_node *lst, int b_index, int elems)
{
	t_node	*tmp;
	int		pos;
	int		elem_pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->b_index == b_index)
			elem_pos = pos;
		tmp = tmp->next;
		pos++;
	}
	return (elem_pos);
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

int	get_node_index_position_from_bottom(t_node *lst, int index, int elems)
{
	t_node	*tmp;
	int		pos;
	int		elem_pos;

	pos = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == index)
			elem_pos = pos;
		tmp = tmp->next;
		pos++;
	}
	return (elem_pos);
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

int	is_current_bucket_sorted(t_stack *stack, int b_index)
{
	t_node	*tmp;

	tmp = stack->b;
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
			if (tmp->next && tmp->index > tmp->next->index)
			{
				return (0);
			}
		}
		tmp = tmp->next;
	}
	tmp = stack->a;
	while (tmp)
	{
		if (tmp->b_index == b_index)
		{
		// 	printf("There's elements of bucket index [%i] in stack A! ********  \n\n", b_index);
		// 	usleep(1600000);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

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
