/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:21:39 by iostancu          #+#    #+#             */
/*   Updated: 2023/03/09 00:34:58 by iostancu         ###   ########.fr       */
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

typedef struct s_bucket
{
	int				b_index;
	int				num_elems;
	struct s_bucket	*next;
}				t_bucket;
/**
 * @brief 
 * 
 * @param bucket_range Range of each bucket
 */
typedef struct	s_stack
{
	t_node		*a;
	t_node		*b;
	t_bucket	b_elems;
	int			elements;
	int			bucket_range;
	int			max_val;
	int			min_val;
	int			max_bucket;
}				t_stack;

#endif
