/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/20 19:51:01 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "gnl.h"
#include "stdio.h"

#define PRINT_    1
#define COLORED    1

#if COLORED
	#define RED_    "\x1b[31m"
	#define GREEN_  "\x1b[32m"
	#define YELLOW_ "\x1b[33m"
	#define BLUE_   "\x1b[34m"
	#define VIOLET_ "\x1b[35m"
	#define CYAN_   "\x1b[36m"
	#define RESET_  "\x1b[0m"
#else
	#define RED_    ""
	#define GREEN_  ""
	#define YELLOW_ ""
	#define BLUE_   ""
	#define VIOLET_ ""
	#define CYAN_   ""
	#define RESET_  ""
#endif

typedef struct	s_iter
{
	int	i;
	int	j;
}				t_iter;

typedef struct	s_moves
{
	int	moves_i_rotate;
	int	moves_i_reverse;
	int	moves_j_rotate;
	int	moves_j_reverse;
}				t_moves;

typedef struct s_node
{
	long int		data;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		elements;
	int		current_a_elems;
	int		current_b_elems;
	int		is_even;
}				t_stack;

t_stack	*alloc_stacks(int argc, char **argv);
t_stack	*alloc_stacks_arr(int argc, int *arr);
int		is_valid_arg(char **stack);
int		is_sorted_arg(t_node **head);
int		is_reverse_sorted(t_node **head);
int		is_duplicated_arg(t_node **head);
void	push_new_node(t_node **head_a, long int data);
char	**read_input_file(int fd, char **split_fd);
int		get_node_position(t_node *lst, int i);
/**
 * @brief Sets num of movements of rotation and reverse rotation
 * to found each iterator.
 * 
 * @param moves Struct
 * @param lst Node to get position by its index
 * @param i Iterator to search
 * @param elems Num of elements in stack
 */
void	count_num_movements(t_moves *moves, t_node *lst, t_iter i, int elems);
/**
 * @brief Makes the movement depending of the smallest num of movements
 * 
 * @param moves Struct
 * @param lst Pointer to entirely stack
 * @param it Struct iterator
*/
void	do_less_rotation_moves(t_moves *moves, t_node **lst, t_iter it);

/**
 * Swaps the first two elements of the head of stack.
 * Nothing to do if stack have < 1 elements.
 * 
 * @param head list to swap
 * @param stack index for msg display. 0 = stack A; 1 = stack B
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
void	f_reverse_rotate(t_node **head, int print, int stack);
/**
 * @brief Rotates the last element of stack to the head. The rest of
 * elements moves down by one position.
 * Nothing to do if stack have < 1 elements.
 * 
 * @param head list to rotate
 * @param print 1 = prints msg, 0 = no print
 * @param stack 0 = if rotates stack A or 1 = if rotates stack B
 */
void	f_rotate(t_node **head, int print, int stack);
void	f_rotate_both(t_stack *stack);

void	add_back(t_node **head, t_node *new_node);
void	add_value_back(t_node **head, long int data);
void	print_args(t_node *stack);
void	print_both_stacks(t_stack *stack, int i, int j);
void	selection_sort(t_stack *stacks);
void	f_sort(t_stack *stack);
long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
t_node	*pop_node(t_node **head);
void	add_front(t_node **head_a, t_node *new_node);
/**
 * @brief Counts how many elements are currently in the indicated stack
 * 
 * @param stack Pointer to stack
 * @param n 0 if is stack A, else if is stack B
 * 
 * @return number of stack elements
 */
int	count_stack_elements(t_stack *stack, int n);

#endif