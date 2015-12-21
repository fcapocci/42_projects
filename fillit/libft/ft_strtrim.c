/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:23:53 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 19:42:57 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		realsize(char *s)
{
	int		b;
	int		a;
	int		lena;

	b = 0;
	lena = 0;
	while (s[b] != '\0' && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	if (s[b] != '\0')
	{
		a = ft_strlen(s) - 1;
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		{
			a--;
			lena++;
		}
	}
	return (ft_strlen(s) - b - lena);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		b;
	int		i;
	int		n;

	b = 0;
	i = 0;
	n = realsize((char*)s);
	while (s[b] != '\0' && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b++;
	str = (char*)malloc(sizeof(*str) * n + 1);
	if (!str)
		return ((void*)0);
	while (i < n)
	{
		str[i] = s[b + i];
		i++;
	}
	while (i < n + 1)
		str[i++] = '\0';
	return (str);
}
