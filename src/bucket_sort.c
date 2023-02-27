/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:08:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/27 17:33:30 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_bucket_sort(t_stack *stack)
{
	int		bucket_i;

	bucket_i = 0;
	// continuing sorting while stack is not sorted and there aren't all elements
	while (stack->a)
	{
		
		if(check_all_elements(stack, 0) && is_sorted_stack(stack->a))
			break ;
		
		bucket_i++;
	}
}
