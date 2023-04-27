/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:24:32 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 23:25:42 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_swap(t_node **head, t_stack *s, int stack, int called)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (!called)
	{
		if (stack == 0)
			ft_putendl_fd(BLUE_, "sa", 1);
		if (stack == 1)
			ft_putendl_fd(BLUE_, "sb", 1);
	}
	print_both_stacks(s);
}

void	f_swap_both(t_stack *stack)
{
	f_swap(&stack->a, stack, 0, 1);
	f_swap(&stack->b, stack, 0, 1);
	ft_putendl_fd(BLUE_, "ss", 1);
	print_both_stacks(stack);
}
