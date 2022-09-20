/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:14:45 by iostancu          #+#    #+#             */
/*   Updated: 2022/02/19 18:10:49 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
