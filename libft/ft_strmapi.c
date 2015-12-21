/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:31:45 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/04 16:06:30 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	char	*scp;
	int		i;

	scp = (char*)s;
	newstr = ft_strnew(ft_strlen(s));
	if (!newstr)
		return (NULL);
	i = 0;
	while (scp[i] != '\0')
	{
		newstr[i] = f(i, scp[i]);
		i++;
	}
	return (newstr);
}
