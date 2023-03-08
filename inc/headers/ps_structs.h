/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:21:39 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/08 20:11:19 by iostancu         ###   ########.fr       */
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
	int				b_index;
	int				is_sorted;
	struct s_node	*next;
}				t_node;

/**
 * @brief 
 * 
 * @param bucket_range Range of each bucket
 */
typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
	int		elements;
	int		current_a_elems;
	int		current_b_elems;
	int		bucket_range;
	int		max_val;
	int		min_val;
	int		is_even;
	int		max_bucket;
}				t_stack;

#endif
