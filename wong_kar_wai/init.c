/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:29:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/31 21:05:54 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check_pow(void)
{
	int		nb;

	nb = 2;
	while (nb < WIN_VALUE)
	{
		nb = nb * 2;
	}
	if (nb == WIN_VALUE)
		return (0);
	return (-1);
}

int			initialisation(int *a, int *b, int **tab, int ***dtab)
{
	*a = 1;
	*b = 0;
	if (check_pow() != 0)
		return (-1);
	if (!(*tab = (int*)malloc(sizeof(int) * 16)))
		return (-1);
	*dtab = ft_d_array(*tab);
	if (*dtab == NULL)
	{
		free(tab);
		return (-1);
	}
	return (0);
}
