/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/28 23:08:56 by iostancu         ###   ########.fr       */
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

void	do_less_rotation_moves(t_temp_node aux, t_stack *stack, int b_index)
{
	int	i;
	int	temp_bottom;

	i = 0;
	temp_bottom = stack->elements - aux.bottom;
	if (aux.top < temp_bottom)
	{
		//printf(" aux.bottom == %i \n\n", aux.bottom);
		do_rotation(get_rotation_type(1), aux.top, &stack->a);
		
		print_both_stacks(stack, 0, 0);
		// printf(" ELEMENTS == %i \n\n", stack->elements);
		// printf(" ELEMENTS / 2 == %i \n\n", stack->elements / 2);
		// usleep(900000);
		
	}
	else
	{
		printf(" aux.top == %i \n\n", aux.top);
		usleep(900000);
		do_rotation(get_rotation_type(0), temp_bottom, &stack->a);
		print_both_stacks(stack, 0, 0);
	}
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
