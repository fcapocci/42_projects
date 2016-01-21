/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:34:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/18 12:08:12 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void*)malloc(sizeof(void) * (size));
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
