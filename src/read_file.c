/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:47:08 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/26 16:16:26 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_fd_end(char *s)
{
	if (s == NULL)// || ft_strncmp(s, "\n", 1) == 0)// || 
		//ft_strncmp(s, " ", 1) == 0)
		return (1);
	else
		return (0);
}

char 	**read_input_file(int fd, char **split_fd)
{
	int		i;

	i = 0;

	while (1)
	{
		split_fd[i] = get_next_line(fd);
		printf("%s\n", split_fd[i]);
		if (check_fd_end(split_fd[i]))
			break ;
		i++;
	}
	return (split_fd);
}

