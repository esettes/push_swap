/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:30:38 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 21:49:06 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*alloc_stacks(int argc, char **argv)
{
	int			i;
	t_stack		*stack;
	int			tmp;
	long int	*arr;
	int			all_args;

	i = 0;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	if (!(stack || stack->a))
		return (NULL);
	stack->b = NULL;
	stack->a->data = ft_atoi(argv[1]);
	stack->a->next = NULL;
	all_args = count_all_args(argc, argv);
	printf("all_args: %i \n", all_args);
	arr = malloc(sizeof(long int) * all_args + 1);
	if (!arr)
		return (0);
	set_all_args(argc, argv, arr);
	printf("heyyyy \n");
	while (i < all_args - 1)
	{
		add_value_back(&stack->a, arr[i]);
		//printf("arr[i]: %i \n", arr[i]);
		i++;
	}
	// while (argc-- > 0 && argv[i + 1])
	// {
	// 	tmp = ft_atoi(argv[i + 1]);
	// 	add_value_back(&stack->a, tmp);
	// 	i++;
	// }
	free (arr);
	return (stack);
}

void	set_all_args(int argc, char **argv, long int *arr)
{
	t_iter	it;
	t_iter	arg;
	char	**tmp;
	int		all_args;

	all_args = count_all_args(argc, argv);
	it.j = 0;
	arg.i = 0;
	while (all_args > 0 && argv[it.j + 1])
	{
		it.i = str_count(argv[it.j + 1], ' ');
		if (it.i > 1)
		{
			arg.j = 0;
			tmp = ft_split(argv[it.j + 1], ' ');
			while (it.i-- >= 0 && tmp[arg.j])
			{
				arr[arg.i] = ft_atoi(tmp[arg.j++]);
				printf("arr[i]: %i \n", *(arr + arg.i));
				arg.i++;
			}
			it.j++;
			free (tmp);
		}
		else
		{
			arr[arg.i] = ft_atoi(argv[it.j + 1]);
			printf("arr[i]: %i \n", *(arr + arg.i));
			arg.i++;
			it.j++;
		}
		all_args--;
	}
	printf("arg.i: %i \n", arg.i);
	arr[arg.i] = '\0';
}

// void	print_both_stacks(t_stack *stack)
// {
// 	(void)stack;
// }

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
			printf(" %ld, %i \t %ld, %i\n",current_a->data,
				current_a->b_index, current_b->data, current_b->b_index);
			current_a = current_a->next;
			current_b = current_b->next;
			aux++;
		}
		else if (current_b)
		{
			printf("   \t %ld, %i\n", current_b->data, current_b->b_index);
			current_b = current_b->next;
		}
		else if (current_a)
		{
			printf(" %ld, %i \t  \n",current_a->data, current_a->b_index);
			current_a = current_a->next;
		}
		aux++;
	}
	#endif
}
