/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:16:13 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 19:22:41 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	while ((s1[i] != '\0') && (i < n))
	{
		j = 0;
		start = i;
		while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j] && (i < n))
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)&(s1[start]));
		i = start + 1;
	}
	return ((void*)0);
}
