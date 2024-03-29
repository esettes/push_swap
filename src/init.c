/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:30:38 by iostancu          #+#    #+#             */
/*   Updated: 2023/05/03 17:22:56 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_temp_args(char **tmp);

t_stack	*alloc_stacks(int argc, char **argv)
{
	int			i;
	t_stack		*stack;
	long int	*arr;
	int			all_args;

	i = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = (t_node *)malloc(sizeof(t_node));
	if (!(stack || stack->a))
		return (NULL);
	stack->b = NULL;
	stack->a->data = ft_atoi(argv[1]);
	stack->a->next = NULL;
	all_args = count_all_args(argc, argv);
	arr = malloc(sizeof(long int) * all_args);
	if (!arr)
		return (0);
	set_all_args(argc, argv, arr);
	while (i < all_args)
		add_value_back(&stack->a, arr[i++]);
	stack->elements = all_args;
	free (arr);
	return (stack);
}

void	set_all_args(int argc, char **argv, long int *arr)
{
	t_iter	it;
	t_iter	arg;
	char	**tmp;
	int		all_args;
	int		save_count;

	all_args = count_all_args(argc, argv);
	it.j = 1;
	arg.i = 0;
	while (all_args-- > 0 && argv[it.j])
	{
		it.i = str_count(argv[it.j], ' ');
		save_count = it.i;
		if (it.i > 1)
		{
			arg.j = 0;
			tmp = ft_split(argv[it.j++], ' ');
			while (it.i-- >= 0 && tmp[arg.j])
				arr[arg.i++] = ft_atoi(tmp[arg.j++]);
			free_temp_args(tmp);
		}
		else
			arr[arg.i++] = ft_atoi(argv[it.j++]);
	}
}

void	free_temp_args(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	i--;
	while (tmp[i])
		free (tmp[i--]);
	free (tmp);
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
	printf("MAX VAL: %d \n", stack->max_val);
	printf("Elements: %d \n", stack->elements);
	printf("Bucket range: %d \n", stack->bucket_range);
	printf("\n+ + + + + + + +\n\n");
	printf("|A|\t|B|\n");
	while (aux <= stack->elements + 1)
	{
		if (current_a && current_b)
		{
			printf(" %ld \t %ld\n",current_a->data, current_b->data);
			current_a = current_a->next;
			current_b = current_b->next;
			aux++;
		}
		else if (current_b)
		{
			printf("   \t %ld\n", current_b->data);
			current_b = current_b->next;
		}
		else if (current_a)
		{
			printf(" %ld\t  \n",current_a->data);
			current_a = current_a->next;
		}
		aux++;
	}
	#endif
}
