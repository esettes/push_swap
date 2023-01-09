/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:28:17 by iostancu          #+#    #+#             */
/*   Updated: 2023/01/09 20:37:02 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *stacks)
{
	t_iter	iter;
	int		index;
	t_node	*current;
	t_node	*next;

	current = stacks->a;
	iter.i = 0;
	iter.j = 0;
	index = 0;
	printf("\nIndexing....\n");
	while (current->next != NULL)
	{
		next = current->next;
		while (next != NULL)
		{
			if (current->data > next->data)
			{
				printf("Is %ld > %ld? \tIndex: %d\n",current->data, next->data, index);
				next->index = index;
				//printf("next < current %d \t %d\n",next->data, next->index);
			}
			else if (current->data < next->data)
			{
				printf("Is %ld < %ld? \tIndex: %d\n",current->data, next->data, index);
				current->index = index;
				//printf("next > current %d \t %d\n",current->data, current->index);
			}
			next = next->next;
		}
		current = current->next;
		index++;
	}
	current = stacks->a;
	printf("\nPrint....\n");
	while (current != NULL)
	{
		printf("%d \t %d\n",current->data, current->index);
		current = current->next;
	}
}
