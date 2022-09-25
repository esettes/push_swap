/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:24:32 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/23 04:11:39 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **head, int called)
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
		ft_putendl_fd(BLUE_,"sa", 1);
}

/*
void	swap_a(t_stack *stack, int called)
{
	int	i;
	int	aux;

	i = 1;
	if (!(stack->a[i + 1]))
		return ;
	aux = stack->a[i];
	stack->a[i] = stack->a[i + 1];
	stack->a[i + 1] = aux;
	if (!called)
		ft_putendl_fd(BLUE_,"sa", 1);
}

void	swap_b(t_stack *stack, int called)
{
	int	i;
	int	aux;

	i = 1;
	if (!(stack->b[i + 1]))
		return ;
	aux = stack->b[i];
	stack->b[i] = stack->b[i + 1];
	stack->b[i + 1] = aux;
	if (!called)
		ft_putendl_fd(BLUE_,"sb", 1);
}

void	swap_a_b(t_stack *stack)
{
	swap_a(stack, 1);
	swap_b(stack, 1);
	ft_putendl_fd(BLUE_,"ss", 1);
}
*/