/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:58:00 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/02 10:23:57 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signe(int n)
{
	int		signe;

	signe = 0;
	if (n > 0)
		signe = 1;
	if (n < 0)
		signe = -1;
	return (signe);
}

static int	ft_lennbr(int n)
{
	int		len;

	len = 0;
	if (ft_signe(n) <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		signe;

	signe = ft_signe(n);
	i = ft_lennbr(n);
	str = ft_strnew(i);
	i--;
	if (str)
	{
		if (n == 0)
		{
			str[i] = '0';
			return (str);
		}
		while (n != 0)
		{
			str[i--] = (n % 10 * signe) + 48;
			n /= 10;
		}
		if (signe < 0)
			str[i] = '-';
		return (str);
	}
	return (NULL);
}
