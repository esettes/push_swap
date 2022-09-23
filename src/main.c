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
int		push_swap(int argc, char **argv);
long 	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);

int		main(int argc, char **argv)
{
	if (push_swap(argc, argv))
		ft_putendl_fd(RESET_,"Finish.", 1);
	return (0);
}

void	free_stack(t_st *stack)
{
	free(stack->item);
	free(stack);
}

int		push_swap(int argc, char **argv)
{
	t_stack	*stack;
	long int size;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	size = sizeof(long int);
	if (is_valid_arg(argv))
	{
		ft_putendl_fd(GREEN_,"Valid arguments!", 1);
		alloc_stacks(argc, argv, stack);
		/*if (is_sorted_arg(argc, stack))
			ft_putendl_fd(RED_,"Stack is sorted! Nothing to do.", 1);
		else
			ft_putendl_fd(BLUE_,"Stack is not sorted! Sort it!", 1);
		if (is_duplicated_arg(argc, stack))
			ft_putendl_fd(RED_,"An argument is duplicated.", 1);
		else
			ft_putendl_fd(BLUE_,"Ok. All arguments are diferent.", 1);
		ft_putendl_fd(VIOLET_,"Before swap A:", 1);
		print_args(argc, stack);
		swap_a(stack, 0);
		ft_putendl_fd(VIOLET_,"After swap A:", 1);*/
		//print_args(argc, stack);
		free_stack(stack->a);
		free(stack);
	}
	else
	{
		ft_putendl_fd(RED_,"Invalid arguments!", 1);
		free(stack);
	}
	
	return (1);
}

