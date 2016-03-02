/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:10:16 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/04 16:22:17 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;

	newstr = (char*)malloc(sizeof(char) * (size) + 1);
	if (newstr)
	{
		ft_bzero(newstr, size + 1);
		return (newstr);
	}
	return (NULL);
}
