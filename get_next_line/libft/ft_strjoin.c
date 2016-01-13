/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:50:26 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/12 17:38:07 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	newstr = ft_strnew(len);
	if (newstr)
	{
		while (s1 && *s1 != '\0')
			newstr[i++] = *s1++;
		while (*s2 != '\0')
			newstr[i++] = *s2++;
		return (newstr);
	}
	return (NULL);
}
