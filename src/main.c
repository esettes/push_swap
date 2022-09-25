/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:52 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/23 04:10:23 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int		is_correct_argument(t_stack *stack);
int		check_arguments(int argc, char **argv);
int		pop_node(t_node **head);
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
void	free_stack(t_node **head);

// int		main(int argc, char **argv)
// {
// 	if (check_arguments(argc, argv))
// 	{
// 		//ft_putendl_fd(RESET_,"Finish.", 1);
// 		ft_putendl_fd(VIOLET_,"Before swap A:", 1);
// 		print_args(stack->a);
// 		swap_a(&stack->a, 0);
// 		ft_putendl_fd(VIOLET_,"After swap A:", 1);
// 		print_args(stack->a);

		
// 	}
// 	free_stack(&stack->a);
// 	free(stack);
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_stack	*stack;

	if (is_valid_arg(argv))
	{
		stack = alloc_stacks(argc, argv);
		if (!stack)
			return (0);
		if (is_correct_argument(stack))
			ft_putendl_fd(GREEN_,"Valid arguments!", 1);
		free_stack(&stack->a);
		free(stack);
	}
	else
	{
		ft_putendl_fd(RED_,"Invalid arguments!", 1);
		return (0);
	}
	return (1);
}

int		is_correct_argument(t_stack *stack)
{
	if (is_sorted_arg(stack->a))
		{
			ft_putendl_fd(RED_,"Stack is sorted! Nothing to do.", 1);
			return (0);
		}
		else
		{
			ft_putendl_fd(BLUE_,"Stack is not sorted! Sort it!", 1);
		}
		if (is_duplicated_arg(stack->a))
		{
			ft_putendl_fd(RED_,"An argument is duplicated.", 1);
			return (0);
		}
		else
		{
			ft_putendl_fd(BLUE_,"Ok. All arguments are diferent.", 1);
			
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

