/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:27:15 by vcastro-          #+#    #+#             */
/*   Updated: 2015/11/25 19:41:31 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*as1;
	unsigned char	*as2;

	as1 = (unsigned char*)s1;
	as2 = (unsigned char*)s2;
	while (*as1 != '\0' && *as2 != '\0' && *as1 == *as2)
	{
		as1++;
		as2++;
	}
	if (*as1 > *as2)
		return (1);
	else if (*as1 < *as2)
		return (-1);
	return (0);
}
