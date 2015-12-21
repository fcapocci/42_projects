/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:15:33 by fcapocci          #+#    #+#             */
/*   Updated: 2015/11/25 11:32:19 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sig;
	int		res;

	sig = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str) != 0)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sig);
}
