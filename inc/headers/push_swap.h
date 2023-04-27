/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 21:33:10 by iostancu         ###   ########.fr       */
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

#define PRINT_	0
#define COLORED	0

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
int		is_valid_arg(char **argv, int argc);
int		is_sorted_stack(t_node **head);
int		is_reverse_sorted(t_node **head);
int		is_duplicated_arg(t_node **head);

void	print_both_stacks(t_stack *stack);
/**
 * @brief Counts how many elements are currently in the indicated stack
 * 
 * @param node Pointer to stack
 * 
 * @return number of stack elements
 */
int		count_stack_elements(t_node *node);
/**
 * @brief Sorts the stack in a temporal stack to sets indexes to each elem
 */
void	set_index_to_each_elem(t_stack *stacks);
/**
 * @brief Main function that calls others related to bucket sort initialization
 * 
 * @param stack
 * @param lst
 */
void	set_bucket_sort_values(t_stack *stack, t_node *lst);
void	sort_three_elems(t_stack *stack, t_node *node);
void	f_insertion_sort(t_stack *stack);

int		get_node_position_from_bottom(t_stack *stack, t_node *lst, int b_index,
	int elems);
int		get_node_position_from_top(t_stack *stack, t_node *lst, int b_index);
void	put_least_elem_of_b_to_head(t_stack *stack, int b_index);
int		are_elems_of_current_bucket_in_stack(t_node *stack, int b_index);
int		get_node_index_position_from_bottom(t_node *lst, int i, int elems);
int		get_node_index_position_from_top(t_node *lst, int index);
int		is_one_of_three_biggest_elems(t_stack *stack, int val);

void	do_less_rotation_moves_a(t_temp aux, t_stack *s, t_node **l);
void	do_less_rotation_moves_b(t_temp aux, t_stack *s, t_node **l, int index);

int		return_biggest_elems_from_b(t_stack *stack, t_node *node);
void	sort_stack_a(t_stack *stack);
/**
 * @brief Free a t_node struct
 * 
 * @param head Pointer to node
 */
void	free_stack(t_node **head);
/**
 * @brief Free a t_stack struct
 * 
 * @param stack Pointer to stack
 */
void	free_entire_stack(t_stack *stack);
long	ft_strtol(const char *nptr, char **endptr, int base);
int		count_all_args(int argc, char **argv);
int		str_count(char const *s, char c);
int		are_correct_chars(char **argv);
void	set_all_args(int argc, char **argv, long int *arr);

#endif
