/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/23 04:11:23 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_valid_arg(char **stack)
{
	char 		*ptr;
    long int 	ret;
    int 		i;
	
	i = 1;
	ft_putendl_fd(RESET_,"Arguments validation...", 1);
    while (stack[i])
    {
        ptr = NULL;
        ret = ft_strtol(stack[i], &ptr, 10);
        if (*ptr)
        {
            //printf("Error!: %s\n", ptr);
            return (0);
        }
        i++;
    }
	return (1);
}

/*
int	is_sorted_arg(int pos, t_stack *stack)
{
	int	i;

	i = 1;
	if (pos == 1)
        return (1);
	while (i < pos)
    {
	    if (stack->a[i - 1] > stack->a[i])
            return (0);
		i++;
	}
    return (1);
}
*/
/*
int is_duplicated_arg(int pos, t_stack *stack)
{
    int	i;
    int aux;

	i = 1;
	if (pos == 1)
        return (1);
	while (i < pos)
    {
        aux = i;
        
        while (aux + 1 < pos)
        {
            if (stack->a[i] == stack->a[aux + 1])
                return (1);
            aux++;
        }
        i++;
	}
    return (0);
}
*/
