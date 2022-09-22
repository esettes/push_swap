/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:20:51 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/21 21:44:57 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid_args(int pos, char **stack)
{
	char 		*ptr;
    long int 	ret;
    int 		i;
	
	i = 1;
	ft_putendl_fd(RESET_,"Arguments validation...", 1);
    while (stack[i])
    {
        ptr = NULL;
        ret = f_strtol(stack[i], &ptr, 10);
        printf("%s\n", stack[i]);
        if (*ptr)
        {
            printf("Error!: %s_\n", ptr);
            return (0);
        }
        i++;
    }
	return (1);
}

// int	check_valid_args(char **stack)
// {
// 	t_iter	it;
	
// 	it.i = 1;
	
// 	while (stack[it.i])
// 	{
// 		it.j = 0;
// 		if (stack[it.i][it.j])
// 		{
// 			while (stack[it.i][it.j])
// 			{
// 				if (ft_isnumsymbol(stack[it.i][it.j]) || ft_isdigit(stack[it.i][it.j]))
// 					it.j++;
// 				else
// 					return (0);
// 			}
// 		}
// 		if (ft_isnumsymbol(stack[it.i][it.j]) || ft_isdigit(stack[it.i][it.j]))
// 			it.i++;
// 		else
// 			return (0);
// 	}
// 	return (1);


// t_iter	it;
// 	char	*ptr;
// 	long int	**ret;

// 	it.i = 1;
	
// 	ret = malloc(sizeof(long int **));
// 	while (stack[it.i])
// 	{
// 		ptr = NULL;
// 		ret[it.i] = strtol(stack[it.i], &ptr, 10);
// 		//ptr = NULL;
// 		printf("%s\n", stack[it.i]);
// 		if (*ptr)
// 		{
// 			printf("%s_", ptr);
// 			return (0);
// 			}
// 		it.i++;
// 	}
// }

