/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:06:05 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/03 17:15:28 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*s;
	char		*d;
	size_t		nsize;
	size_t		dstlen;

	d = dst;
	s = src;
	nsize = size;
	while (nsize-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	nsize = size - dstlen;
	if (nsize == 0)
		return (dstlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (nsize != 1)
		{
			*d++ = *s;
			nsize--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
