/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:33:58 by fcapocci          #+#    #+#             */
/*   Updated: 2015/11/27 12:06:26 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		p = 0;
		j = i;
		while (s1[j] == s2[p] && j < n)
		{
			j++;
			p++;
			if (!s2[p])
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
