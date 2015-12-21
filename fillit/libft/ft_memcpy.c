/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:45:15 by vcastro-          #+#    #+#             */
/*   Updated: 2015/11/23 17:09:48 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*asrc;
	char	*adst;
	size_t	i;

	asrc = (char*)src;
	adst = (char*)dst;
	i = 0;
	while (i < n)
	{
		adst[i] = asrc[i];
		i++;
	}
	return (dst);
}
