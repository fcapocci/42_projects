/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:49:56 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 18:51:29 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*scopy;
	int		i;

	i = 0;
	scopy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (scopy)
		while (s1[i] != '\0')
		{
			scopy[i] = s1[i];
			i++;
		}
	else
		return ((void*)0);
	scopy[i] = '\0';
	return (scopy);
}
