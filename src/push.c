/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 00:47:46 by iostancu          #+#    #+#             */
/*   Updated: 2023/01/15 22:43:27 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_push(t_node **src, t_node **dst, int print, int stack)
{
	t_node	*tmp;
	long int	ret;

	if (*src)
	{
		tmp = pop_node(src);
		if (tmp == NULL)
			return ;
		add_front(dst, tmp);
		if (print)
		{
			if (stack == 1)
				ft_putendl_fd(CYAN_, "pa", 1);
			else if (stack == 2)
				ft_putendl_fd(CYAN_, "pb", 1);
		}
	}
}
