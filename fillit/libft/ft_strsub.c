/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:27:12 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 19:33:41 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tronc;

	i = 0;
	tronc = malloc(sizeof(char) * (len + 1));
	if (!tronc)
		return ((void*)0);
	while (i < len)
	{
		tronc[i] = s[start + i];
		i++;
	}
	while (i < len + 1)
		tronc[i++] = '\0';
	return (tronc);
}
