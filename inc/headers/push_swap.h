/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:57 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/23 04:22:43 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "stdio.h"

#define RED_    "\x1b[31m"
#define GREEN_  "\x1b[32m"
#define YELLOW_ "\x1b[33m"
#define BLUE_   "\x1b[34m"
#define VIOLET_ "\x1b[35m"
#define CYAN_   "\x1b[36m"
#define RESET_  "\x1b[0m"

typedef struct	s_iter
{
	int	i;
	int	j;
}				t_iter;

typedef struct s_node
{
	long int		data;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
}				t_stack;

// typedef struct	s_stack
// {
// 	int	*a;
// 	int	*b;
// }				t_stack;

void    print_args(t_node *stack);
int		is_valid_arg(char **stack);
int		is_sorted_arg(t_node *head);
t_stack	*alloc_stacks(int argc, char **argv);
int		is_duplicated_arg(t_node *head);

/**
 * Swaps the first two elements of the head of stack A.
 * Nothing to do if stack A have < 1 elements.
 */
void	swap_a(t_node **head, int called);
/**
 * Swaps the first two elements of the head of stack B.
 * Nothing to do if stack B have < 1 elements.
 */
void	swap_b(t_stack *stack, int called);
/**
 * Swaps the first two elements of the head of stack A and B.
 * Nothing to do if stack A or stack B has < 1 elements.
 */
void	swap_a_b(t_stack *stack);

/**
 * @brief Gets the first item of stack B and puts it at stack A head.
 * Nothing to do if stack B is NULL.
 * 
 * @param stack 
 */
void	push_a(t_stack *stack);
/**
 * @brief Gets the first item of stack A and puts it at stack B head.
 * Nothing to do if stack A is NULL.
 * 
 * @param stack 
 */
void	push_b(t_stack *stack);

#endif