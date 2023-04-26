/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:25:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/26 17:26:24 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_correct_chars(char **argv)
{
	int	i;
	int	j;

	j = 0;
	if (argv[1] == NULL)
		return (0);
	while (argv[++j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] == '-' && !(ft_isdigit(argv[j][i + 1])))
				return (0);
			if (argv[j][i] == '+' && !(ft_isdigit(argv[j][i + 1])))
				return (0);
			if (!(ft_isdigit(argv[j][i]) || ft_isspace(argv[j][i])
				|| argv[j][i] == '-' || argv[j][i] == '+'))
				return (0);
			i++;
		}
	}
	return (1);
}

int	are_all_integers(long int *arr, int i)
{
	int	j;

	j = 0;
	while (++j < i - 1)
	{
		if (arr[j] > 2147483647 || arr[j] < -2147483648)
		{
			free (arr);
			return (0);
		}
	}
	return (1);
}
