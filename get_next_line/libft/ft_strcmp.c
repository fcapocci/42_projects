/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:09 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/01 13:01:05 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (us1 && *us1 == *us2)
	{
		if (*us1 == '\0')
			return (0);
		us1++;
		us2++;
	}
	if (*us1 < *us2)
		return (-1);
	else if (*us1 > *us2)
		return (1);
	else
		return (0);
}
