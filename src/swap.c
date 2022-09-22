/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:24:32 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/23 00:46:31 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	i;
	int	aux;

	i = 1;
	if (!(stack->a[i + 1]))
		return ;
	aux = stack->a[i];
	stack->a[i] = stack->a[i + 1];
	stack->a[i + 1] = aux;
}

void	swap_b(t_stack *stack)
{
	int	i;
	int	aux;

	i = 1;
	if (!(stack->b[i + 1]))
		return ;
	aux = stack->b[i];
	stack->b[i] = stack->b[i + 1];
	stack->b[i + 1] = aux;
}

void	swap_a_b(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}
