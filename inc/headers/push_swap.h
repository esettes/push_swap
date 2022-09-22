/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:00:57 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/21 21:48:12 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

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

int	check_valid_args(int pos, char **stack);

#endif