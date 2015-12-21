/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:46:44 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/11 19:49:11 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_baselen(int n, int base)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	int		i;
	int		end;

	i = 0;
	if (base == 10)
		return (ft_itoa(value));
	if (value == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = ft_baselen(value, base);
	str = malloc(sizeof(char) * (i + 1));
	end = i;
	i--;
	while (value != 0)
	{
		str[i--] = value % base + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	str[end] = '\0';
	return (str);
}
