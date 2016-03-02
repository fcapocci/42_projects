/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:22:49 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/05 16:20:41 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*newstr;
	int		i;
	int		sav1;
	int		sav2;

	sav1 = 0;
	sav2 = ft_strlen(s);
	i = 0;
	while (s[sav1] == ' ' || s[sav1] == '\n' || s[sav1] == '\t')
		sav1++;
	while (s[sav2] == ' ' || s[sav2] == '\n' || s[sav2] == '\t'
			|| s[sav2] == '\0')
		sav2--;
	if ((newstr = ft_strnew(ft_strlen(s))))
	{
		while (sav1 <= sav2)
			newstr[i++] = s[sav1++];
		return (newstr);
	}
	return (NULL);
}
