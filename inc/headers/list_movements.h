/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_movements.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:23:39 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 16:27:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_MOVEMENTS_H
# define LIST_MOVEMENTS_H

#include "ps_structs.h"

void	push_new_node(t_node **head_a, long int data);
void	add_back(t_node **head, t_node *new_node);
void	add_value_back(t_node **head, long int data);
t_node	*pop_node(t_node **head);
void	add_front(t_node **head_a, t_node *new_node);

#endif
