/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:41:58 by iostancu          #+#    #+#             */
/*   Updated: 2023/05/02 19:32:42 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_reverse_rotate(t_node **head, t_stack *s, int called, int stack)
{
	t_node	*tmp;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
	tmp->next = *head;
	*head = tmp;
	if (!called)
	{
		if (stack == 0)
			ft_putendl_fd(BLUE_, "rra", 1);
		else if (stack == 1)
			ft_putendl_fd(BLUE_, "rrb", 1);
	}
	print_both_stacks(s);
}

void	f_rotate(t_node **head, t_stack *s, int called, int stack)
{
	t_node		*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = pop_node(head);
	add_back(head, tmp);
	if (!called)
	{
		if (stack == 0)
			ft_putendl_fd(VIOLET_, "ra", 1);
		else if (stack == 1)
			ft_putendl_fd(VIOLET_, "rb", 1);
	}
	print_both_stacks(s);
}

void	f_rotate_both(t_stack *stack)
{
	f_rotate(&stack->a, stack, 0, 0);
	f_rotate(&stack->b, stack, 0, 1);
	ft_putendl_fd(BLUE_, "rr", 1);
	print_both_stacks(stack);
}
