/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:41:31 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 17:44:33 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_min_and_max_values(t_stack *stack, t_node *lst);
int			get_bucket_range(t_stack *stack);
void		set_bucket_indexes(t_stack *stack, t_node *lst);
t_bucket	*get_elems_for_each_bucket(t_stack *stack, t_node *lst);

void	set_bucket_sort_values(t_stack *stack, t_node *lst)
{
	set_min_and_max_values(stack, lst);
	stack->bucket_range = get_bucket_range(stack);
	set_bucket_indexes(stack, lst);
	stack->b_elems = get_elems_for_each_bucket(stack, lst);
}

t_bucket	*get_elems_for_each_bucket(t_stack *stack, t_node *lst)
{
	t_bucket	*b_elems;
	t_bucket	*head;
	int			i;
	int			b_index;

	b_elems = malloc(sizeof(t_bucket) * (stack->max_bucket + 1));
	if (!b_elems)
		return (NULL);
	i = 0;
	while (i <= stack->max_bucket)
	{
		b_elems[i].num_elems = 0;
		b_elems[i].is_sorted = 0;
		i++;
	}
	while (lst)
	{
		b_index = lst->b_index;
		b_elems[b_index].b_index = b_index;
		b_elems[b_index].num_elems += 1;
		lst = lst->next;
	}
	return (b_elems);
}

void	set_min_and_max_values(t_stack *stack, t_node *lst)
{
	int		i;
	t_node	*tmp;
	t_node	*next;

	i = 0;
	tmp = lst;
	stack->min_val = 0;
	stack->max_val = 0;
	while (tmp)
	{
		if (stack->max_val < tmp->index)
		{
			stack->max_val = tmp->index;
		}
		else if (tmp->index < stack->min_val)
		{
			stack->min_val = tmp->index;
		}
		tmp = tmp->next;
	}
}

int	get_bucket_range(t_stack *stack)
{
	if (stack->elements <= 100)
		stack->bucket_range = stack->elements / 5;
	else
		stack->bucket_range = stack->elements / 11;
	if (stack->bucket_range == 0)
		stack->bucket_range = 1;
	return (stack->bucket_range);
}

void	set_bucket_indexes(t_stack *stack, t_node *lst)
{
	int	max_bucket;

	max_bucket = 0;
	while (lst)
	{
		lst->b_index = (lst->index - stack->min_val) / stack->bucket_range;
		max_bucket = lst->b_index;
		lst = lst->next;
	}
	stack->max_bucket = max_bucket;
}
