/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:44:03 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/18 14:45:22 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		return (NULL);
	s2 = ft_strnew(len);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = (s) ? s[start + i] : '\0';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
