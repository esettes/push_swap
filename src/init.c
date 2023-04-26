/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:30:38 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/26 22:01:41 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*alloc_stacks(int argc, char **argv)
{
	char		*ptr;
	long int	ret;
	int			i;
	t_stack		*stack;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	stack->b = NULL;
	ptr = NULL;
	ret = ft_strtol(argv[i], &ptr, 10);
	stack->a->data = ret;
	stack->a->next = NULL;
	i++;
	while (argv[i])
	{
		ptr = NULL;
		ret = ft_strtol(argv[i], &ptr, 10);
		add_value_back(&stack->a, ret);
		i++;
	}
	i--;
	stack->elements = i;
	return (stack);
}

// t_stack	*alloc_stacks(int argc, char **argv)
// {
// 	int		i;
// 	t_stack	*stack;
// 	int		tmp;

// 	i = 1;
// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	stack->a = (t_node *)malloc(sizeof(t_node));
// 	if (!(stack || stack->a))
// 		return (NULL);
// 	stack->b = NULL;
// 	stack->a->data = ft_atoi(argv[1]);
// 	stack->a->next = NULL;
// 	stack->elements = argc - 1;
// 	while (argc-- > 0 && argv[i + 1])
// 	{
// 		tmp = ft_atoi(argv[i + 1]);
// 		add_value_back(&stack->a, tmp);
// 		i++;
// 	}
// 	return (stack);
// }

void	print_both_stacks(t_stack *stack)
{
	(void)stack;
}

/*
void	print_both_stacks(t_stack *stack)
{
	t_node	*current_a;
	t_node	*current_b;
	int		aux;

	#if PRINT_
	usleep(160000);
	printf("\033c");
	current_a = stack->a;
	current_b = stack->b;
	aux = 0;
	printf("\nMIN VAL: %d \n", stack->min_val);
	printf("MAX VAL: %d \n", stack->max_val);
	printf("Elements: %d \n", stack->elements);
	printf("Bucket range: %d \n", stack->bucket_range);
	printf("\n+ + + + + + + +\n\n");
	printf("|A|\t|B|\n");
	while (aux <= stack->elements + 1)
	{
		if (current_a && current_b)
		{
			printf(" %ld, %i \t %ld, %i\n",current_a->index,
				current_a->b_index, current_b->index, current_b->b_index);
			current_a = current_a->next;
			current_b = current_b->next;
			aux++;
		}
		else if (current_b)
		{
			printf("   \t %ld, %i\n", current_b->index, current_b->b_index);
			current_b = current_b->next;
		}
		else if (current_a)
		{
			printf(" %ld, %i \t  \n",current_a->index, current_a->b_index);
			current_a = current_a->next;
		}
		aux++;
	}
	#endif
}
*/
