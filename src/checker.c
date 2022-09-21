/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/21 21:44:57 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_args(char **stack)
{
	t_iter	it;
	
	it.i = 0;
	it.j = 0;
	while (stack[it.i])
	{
		while (stack[it.i][it.j])
		{
			if (ft_isnumsymbol(stack[it.i][it.j]) || ft_isdigit(stack[it.i][it.j]))
				it.j++;
			else
				return (0);
		}
		it.i++;
	}
	return (1);
}