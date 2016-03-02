/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:56:14 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/04 19:28:37 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*m;
	unsigned char	*b;

	m = (unsigned char*)dst;
	b = (unsigned char*)src;
	while (n-- > 0)
	{
		*m = *b;
		m++;
		b++;
	}
	return (dst);
}
