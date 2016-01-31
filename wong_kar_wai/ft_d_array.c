/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 22:22:22 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/30 22:34:22 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			**ft_d_array(int *array)
{
	int		**darray;
	int		i;

	i = 0;
	darray = (int**)malloc(sizeof(int*) * 4);
	while (i < 4)
	{
		darray[i] = &array[i * 4];
		i++;
	}
	i = 0;
	while (i < 16)
	{
		array[i] = 0;
		i++;
	}
	return (darray);
}
