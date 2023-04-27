/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:25:57 by iostancu          #+#    #+#             */
/*   Updated: 2023/04/27 18:29:31 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_correct_chars(char **argv)
{
	int		i;
	int		j;
	char	**tmp;

	j = 0;
	tmp = argv;
	if (tmp[1] == NULL)
		return (0);
	while (tmp[++j])
	{
		i = 0;
		while (tmp[j][i])
		{
			if (tmp[j][i] == '-' && !(ft_isdigit(tmp[j][i + 1])))
				return (0);
			if (tmp[j][i] == '+' && !(ft_isdigit(tmp[j][i + 1])))
				return (0);
			if (!(ft_isdigit(tmp[j][i]) || ft_isspace(tmp[j][i])
				|| tmp[j][i] == '-' || tmp[j][i] == '+'))
				return (0);
			if (ft_isspace(tmp[j][i]) && tmp[j][i + 1] != '\0')
			{
				i++;
				continue ;
			}
			i++;
		}
	}
	return (1);
}

int	str_count(char const *s, char c)
{
	int	count;
	int	bo;
	char	*a;

	count = 0;
	bo = 0;
	a = (char *)s;
	while (*a)
	{
		if (*a != c && bo == 0)
		{
			count++;
			bo = 1;
		}
		if (*a == c)
			bo = 0;
		a++;
	}
	return (count);
}

int	are_all_integers(long int *arr, int i)
{
	int	j;

	j = 0;
	while (++j < i)
	{
		if (arr[j] > 2147483647 || arr[j] < -2147483648)
		{
			free (arr);
			return (0);
		}
	}
	return (1);
}

int	count_all_args(int argc, char **argv)
{
	int	i;
	int	all_args;

	i = 0;
	all_args = 0;
	while (argc-- > 0 && argv[i + 1])
	{
		all_args += str_count(argv[i + 1], ' ');
		i++;
	}
	return (all_args);
}
