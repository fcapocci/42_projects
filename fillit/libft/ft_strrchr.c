/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:04:26 by vcastro-          #+#    #+#             */
/*   Updated: 2015/11/26 14:04:43 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;
	char	*as;

	pos = (void*)0;
	as = (char*)s;
	while (*as != '\0')
	{
		if (*as == c)
			pos = as;
		as++;
	}
	if (c == 0)
		return (as);
	return (pos);
}
