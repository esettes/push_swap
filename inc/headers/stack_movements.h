/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movements.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:26:11 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 16:27:49 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_MOVEMENTS_H
# define STACK_MOVEMENTS_H

#include "ps_structs.h"

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

#endif
