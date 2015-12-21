/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:42:06 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/04 17:37:58 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*as1;
	unsigned char	*as2;

	as1 = (unsigned char*)s1;
	as2 = (unsigned char*)s2;
	i = 0;
	if (as2[0] == '\0')
		return (as1[0] - as2[0]);
	while ((i < n) && (as2[i] != '\0'))
	{
		if (as1[i] != as2[i])
		{
			if (as1[i] > as2[i])
				return (1);
			else if (as1[i] < as2[i])
				return (-1);
		}
		i++;
	}
	return (0);
}
