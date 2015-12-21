/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:50:00 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/07 11:23:16 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	str = malloc(sizeof(*str) * (nblen(n) + 1));
	if (!str)
		return ((void*)0);
	if (n == 0)
		str[0] = '0';
	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[i++] = '-';
	}
	i = nblen(n) - 1;
	str[i + 1] = '\0';
	while (n != 0)
	{
		str[i--] = (n % 10) * sign + 48;
		n = n / 10;
	}
	return (str);
}
