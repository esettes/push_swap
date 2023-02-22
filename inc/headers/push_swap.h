/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 21:46:50 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include "gnl.h"
#include "stdio.h"
#include "ps_structs.h"
#include "list_movements.h"
#include "stack_movements.h"

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

t_stack	*alloc_stacks(int argc, char **argv);
t_stack	*alloc_stacks_arr(int argc, int *arr);
int		is_valid_arg(char **stack);
int		is_sorted_arg(t_node **head);
int		is_reverse_sorted(t_node **head);
int		is_duplicated_arg(t_node **head);
char	**read_input_file(int fd, char **split_fd);
int		get_node_position(t_node *lst, int i);
/**
 * @brief Return true if a node in head of stack A is pushed to stack B
*/
int		pushed_current_index(t_stack *stack, t_iter *iter, int middle);
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
void	do_less_rotation_moves(int elems, t_moves *moves, t_node **lst, t_iter it);
void	print_args(t_node *stack);
void	print_both_stacks(t_stack *stack, int i, int j);
long	ft_strtol(const char *restrict nptr, char **restrict endptr, int base);
/**
 * @brief Counts how many elements are currently in the indicated stack
 * 
 * @param stack Pointer to stack
 * @param n 0 if is stack A, else if is stack B
 * 
 * @return number of stack elements
 */
int		count_stack_elements(t_stack *stack, int n);
void	set_index_to_each_elem(t_stack *stacks);
void	f_sort(t_stack *stack);
void	set_bucket_sort_values(t_stack *stack, t_node *lst);

#endif
