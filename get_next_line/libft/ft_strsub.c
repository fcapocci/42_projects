/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:44:03 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/03 11:31:15 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	newstr = ft_strnew(len);
	if (newstr)
	{
		i = 0;
		while (len-- > 0)
			newstr[i++] = s[start++];
		newstr[i++] = '\0';
		return (newstr);
	}
	return (NULL);
}
