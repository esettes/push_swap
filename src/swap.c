/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:24:32 by iostancu          #+#    #+#             */
/*   Updated: 2023/01/16 23:27:54 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_swap(t_node **head, int stack, int called)
{
	t_node *first;
	t_node *second;

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
			ft_putendl_fd(BLUE_,"sa", 1);
		if (stack == 1)
			ft_putendl_fd(BLUE_,"sb", 1);
	}
}

void	f_swap_both(t_stack *stack)
{
	f_swap(&stack->a, 0, 1);
	f_swap(&stack->b, 0, 1);
	ft_putendl_fd(BLUE_,"ss", 1);
}
