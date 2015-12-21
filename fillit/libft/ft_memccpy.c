/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:11:35 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/07 11:39:05 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*asrc;
	unsigned char	*adst;

	asrc = (unsigned char*)src;
	adst = (unsigned char*)dst;
	while (n--)
	{
		*adst = *asrc;
		if (*asrc == (unsigned char)c)
			return (adst + 1);
		adst++;
		asrc++;
	}
	return ((void*)0);
}
