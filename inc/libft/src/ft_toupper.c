/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:24:34 by iostancu          #+#    #+#             */
/*   Updated: 2022/01/22 21:27:09 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uch;

	uch = (unsigned char)c;
	if (c >= 'a' && c <= 'z')
	{
		uch = uch - 32;
		c = (int)uch;
	}
	return (c);
}
