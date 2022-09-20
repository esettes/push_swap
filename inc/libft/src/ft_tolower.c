/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:33:13 by iostancu          #+#    #+#             */
/*   Updated: 2022/01/23 13:22:24 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	uch;

	uch = (unsigned char)c;
	if (c >= 'A' && c <= 'Z')
	{
		uch = uch + 32;
		c = (int)uch;
	}
	return (c);
}
