/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:39:19 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 18:57:00 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*as;

	as = (unsigned char*)s;
	while (n > 0)
	{
		if (*as == (unsigned char)c)
			return (as);
		as++;
		n--;
	}
	return (0);
}
