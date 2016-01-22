/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:22:30 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/03 15:37:45 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *us1;
	unsigned char *us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*us1 != *us2)
		{
			if (*us1 > *us2)
				return (1);
			else
				return (-1);
		}
		if (*us1 == '\0')
			return (0);
		us1++;
		us2++;
	}
	return (0);
}
