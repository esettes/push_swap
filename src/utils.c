/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:26:08 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/12 22:14:01 by iostancu         ###   ########.fr       */
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
	int	current_elems;

	i = 0;
	current_elems = count_stack_elements(stack, 0);
	temp_bottom = current_elems - aux.bottom;
	// printf("t---- current_elems: %i\n",  current_elems);
	// printf("t---- aux.bottom: %i\n",  aux.bottom);
	// printf("t---- temp_bottom: %i\n",  temp_bottom);
	// usleep(1000000);
	if (aux.top < temp_bottom)
	{
		// do_rotation(get_rotation_type(0), aux.top, &stack->a);
		// print_both_stacks(stack, 0, 0);

		while (aux.top != 0)
		{
			f_rotate(&stack->a, 1, 1);
			// printf("node.top position: %i\n", aux.top);
			// usleep(1000000);
			// print_both_stacks(stack, 0, 0);
			aux.top--;
		}
		
	}
	else
	{
		
		// do_rotation(get_rotation_type(1), temp_bottom, &stack->a);
		// print_both_stacks(stack, 0, 0);
		while (temp_bottom != 0)
		{
			f_reverse_rotate(&stack->a, 1, 1);
			// printf("temp_bottom position: %i\n", temp_bottom);
			// usleep(1000000);
			// print_both_stacks(stack, 0, 0);
			temp_bottom--;
		}
	}
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
