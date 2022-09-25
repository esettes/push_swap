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

t_stack	*alloc_stacks(int argc, char **argv);
int		is_valid_arg(char **stack);
int		is_sorted_arg(t_node *head);
int		is_duplicated_arg(t_node *head);

/**
 * @brief Swaps the first two elements of the head of stack.
 * Nothing to do if stack have < 1 elements.
 * 
 * @param head list to swap
 * @param stack index for msg display. 1 = stack A; 2 = stack B
 * @param called 1 = if function is called from swap_both or 0 = if not
 */ 
void	f_swap(t_node **head, int stack, int called);
/**
 * @brief Swaps the first two elements of the head of stack A and B.
 * Nothing to do if stack A or stack B has < 1 elements.
 * 
 * @param stack
 */
void	f_swap_both(t_stack *stack);
/**
 * @brief Gets the first item of stack src and puts it at stack dst head.
 * Nothing to do if stack src is NULL.
 * 
 * @param src 
 * @param dst
 * @param print 1 = prints msg, 0 = no print
 * @param stack 1 = if puts elem to stack A, 2 = if puts elem to stack B
 */
void	f_push(t_node **src, t_node **dst, int print, int stack);

/**
 * @brief Rotates the head element of stack to the bottom. The rest of 
 * elements moves up by one position.
 * Nothing to do if stack have < 1 elements.
 * 
 * @param head list to rotate
 * @param print 1 = prints msg, 0 = no print
 * @param stack 1 = if rotates stack A or 2 = if rotates stack B
 */
void    f_reverse_rotate(t_node **head, int print, int stack);
/**
 * @brief Rotates the last element of stack to the head. The rest of
 * elements moves down by one position.
 * Nothing to do if stack have < 1 elements.
 * 
 * @param head list to rotate
 * @param print 1 = prints msg, 0 = no print
 * @param stack 1 = if rotates stack A or 2 = if rotates stack B
 */
void    f_rotate(t_node **head, int print, int stack);

void    add_back(t_node *head, long int data);
void    print_args(t_node *stack);
void    print_both_stacks(t_stack *stack);

#endif