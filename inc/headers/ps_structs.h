/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:21:39 by iostancu          #+#    #+#             */
/*   Updated: 2023/02/22 16:22:55 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCTS_H
# define PS_STRUCTS_H

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

#endif