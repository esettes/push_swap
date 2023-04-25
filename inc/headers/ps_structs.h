/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:21:39 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/25 23:46:44 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STRUCTS_H
# define PS_STRUCTS_H

typedef struct	s_iter
{
	int	i;
	int	j;
}				t_iter;

typedef struct	s_temp
{
	int	top;
	int	bottom;
}				t_temp;

typedef struct	s_node
{
	long int		data;
	int				index;
	int				b_index;
	struct s_node	*next;
}				t_node;

typedef struct	s_bucket
{
	int	b_index;
	int	num_elems;
	int	min_val;
	int	max_val;
	int	is_sorted;
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
	t_bucket	*b_elems;
	int			elements;
	int			bucket_range;
	int			max_val;
	int			min_val;
	int			max_bucket;
	int			max_values[3];
}				t_stack;

#endif
