/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:22:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/07 14:18:58 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcmpt(char const *s, char c)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	while (*s)
	{
		if (i == 0 && *s != c)
		{
			i = 1;
			cmpt++;
		}
		else if (i == 1 && *s == c)
			i = 0;
		s++;
	}
	return (cmpt);
}

static int	ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tabs;
	int		i;
	int		nb_word;

	i = 0;
	if ((s == NULL) || (*s == '\0'))
		return (NULL);
	nb_word = ft_wordcmpt(s, c);
	tabs = (char**)malloc(sizeof(char*) * (nb_word + 1));
	if (!tabs)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		tabs[i] = ft_strsub(s, 0, ft_wordlen(s, c));
		if (tabs[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	tabs[i] = NULL;
	return (tabs);
}
