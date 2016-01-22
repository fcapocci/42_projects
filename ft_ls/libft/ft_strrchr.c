/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:40:39 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/03 13:38:49 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = (NULL);
	while (*str != '\0')
	{
		if (*str == c)
			tmp = (char*)str;
		str++;
	}
	if (*str == c)
		tmp = (char*)str;
	return (tmp);
}
