/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:14:57 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 19:38:21 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*str;
	unsigned int		len;

	len = ft_strlen(s);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ((void*)0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	while (i < len + 1)
		str[i++] = '\0';
	return (str);
}
