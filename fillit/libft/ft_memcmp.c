/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:48:29 by vcastro-          #+#    #+#             */
/*   Updated: 2015/11/23 20:00:11 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	u1;
	unsigned char	u2;

	while (n--)
	{
		u1 = *(unsigned char*)s1;
		u2 = *(unsigned char*)s2;
		s1++;
		s2++;
		if (u1 != u2)
			return (u1 - u2);
	}
	return (0);
}
