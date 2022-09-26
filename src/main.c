/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:52 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/26 19:20:00 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "fcntl.h"

int		is_correct_argument(t_stack *stack);
int		pop_node(t_node **head);
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
void	free_stack(t_node **head);
int		*myRandInRange();

int		main(int argc, char **argv)
{
	t_stack	*stack;
	int		fd;
	char	**input;
	int 	i;
	int		*arr;

	i = 0;
	//fd = open(argv[1], O_WRONLY);
	//input = malloc(sizeof(char *) * 10000);
	//read_input_file(fd, input);
	//close(fd);
	// while (input[i])
	// {
	// 	printf("%s\n", input[i]);
	// 	i++;
	// }
	arr = myRandInRange();
	if (is_valid_arg(argv))
	{
		//stack = alloc_stacks(argc, argv);
		stack = alloc_stacks_arr(argc, arr);
		if (!stack)
			return (0);
		if (is_correct_argument(stack))
		{
			ft_putendl_fd(GREEN_,"Valid arguments!", 1);
			print_args(stack->a);
			printf("* * * *\n");
			f_rotate(&stack->a, 1, 1);
			//f_push(&stack->a, &stack->b, 1, 2);
			//f_push(&stack->a, &stack->b, 1, 2);
			//print_args(stack->a);
			print_both_stacks(stack);
		}
		else
		{
			ft_putendl_fd(RED_,"Error", 1);
		}
		free_stack(&stack->a);
		free_stack(&stack->b);
		free(stack);
	}
	else
	{
		ft_putendl_fd(RED_,"Invalid arguments!", 1);
		return (0);
	}
	free (arr);
	return (1);
}

int		is_correct_argument(t_stack *stack)
{
	if (is_sorted_arg(stack->a))
	{
		//ft_putendl_fd(RED_,"Stack is sorted! Nothing to do.", 1);
		return (0);
	}
	if (is_duplicated_arg(stack->a))
	{
		//ft_putendl_fd(RED_,"An argument is duplicated.", 1);
		return (0);
	}
	return (1);
}

void	free_stack(t_node **head)
{
	while(*head != NULL)
	{
		pop_node(head);
	}
}

