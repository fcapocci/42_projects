/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:30:49 by vcastro-          #+#    #+#             */
/*   Updated: 2015/11/23 17:36:33 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	tmp[len];
	char	*adst;
	char	*asrc;
	size_t	i;

	i = 0;
	adst = (char*)dst;
	asrc = (char*)src;
	while (i < len)
	{
		tmp[i] = asrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		adst[i] = tmp[i];
		i++;
	}
	return (dst);
}
