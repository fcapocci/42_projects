/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:09:44 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/04 16:24:34 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	char	*scp;
	int		i;

	scp = (char*)s;
	i = 0;
	newstr = ft_strnew(ft_strlen(s));
	if (!newstr)
		return (NULL);
	while (scp[i] != '\0')
	{
		newstr[i] = f(scp[i]);
		i++;
	}
	return (newstr);
}
