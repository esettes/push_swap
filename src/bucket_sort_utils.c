/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:41:31 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/02 16:49:05 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_and_max_values(t_stack *stack, t_node *lst);
int		get_bucket_range(t_stack *stack);
void	set_bucket_indexes(t_stack *stack, t_node *lst);

void	set_bucket_sort_values(t_stack *stack, t_node *lst)
{
	set_min_and_max_values(stack, lst);
	stack->bucket_range = get_bucket_range(stack);
	set_bucket_indexes(stack, lst);
}

void	set_min_and_max_values(t_stack *stack, t_node *lst)
{
	int		i;
	t_node	*tmp;
	t_node	*next;

	i = 0;
	tmp = lst;
	stack->min_val = lst->data;
	stack->max_val = lst->data;
	while (tmp)
	{
		if (stack->max_val < tmp->data)
		{
			stack->max_val = tmp->data;
		}
		else if (tmp->data < stack->min_val)
		{
			stack->min_val = tmp->data;
		}
		tmp = tmp->next;
	}
}

int	get_bucket_range(t_stack *stack)
{
	printf(" +++++ Stack elements: %d +++++\n", stack->elements);
	stack->bucket_range	= (stack->max_val - stack->min_val) / stack->elements;
	return (stack->bucket_range);
}

void	set_bucket_indexes(t_stack *stack, t_node *lst)
{
	int	max_bucket;

	max_bucket = 0;
	while (lst)
	{
		usleep(500000);
		lst->b_index = (lst->data - stack->min_val) / stack->bucket_range;
		printf("For %d, bucketindex: %d\n", lst->data, lst->b_index);
		max_bucket = lst->b_index;
		lst = lst->next;
	}
	stack->max_bucket = max_bucket;
	printf("max bucket: %d\n", stack->max_bucket);
	usleep(500000);
}
