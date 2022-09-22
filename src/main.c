/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:52 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/22 23:36:58 by iostancu         ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

int		push_swap(int argc, char **argv)
{
	t_stack	*stack;
	
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (is_valid_arg(argv))
	{
		ft_putendl_fd(GREEN_,"Valid arguments!", 1);
		alloc_stacks(argc, argv, stack);
		if (is_sorted_arg(argc, stack))
			ft_putendl_fd(RED_,"Stack is sorted! Nothing to do.", 1);
		else
			ft_putendl_fd(BLUE_,"Stack is not sorted! Sort it!", 1);
		if (is_duplicated_arg(argc, stack))
			ft_putendl_fd(RED_,"An argument is duplicated.", 1);
		else
			ft_putendl_fd(BLUE_,"Ok. All arguments are diferent.", 1);
	}
	else
		ft_putendl_fd(RED_,"Invalid arguments!", 1);
	free_stack(stack);
	return (1);
}

