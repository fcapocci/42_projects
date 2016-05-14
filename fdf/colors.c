/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 09:47:49 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/11 10:09:00 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				color_pos(int h)
{
	if (h == 1)
		return (0xfefee0);
	if (h < 5)
		return (0x7fdd4c);
	if (h < 30)
		return (0x149414);
	if (h < 80)
		return (0x22780f);
	if (h < 100)
		return (0xcecece);
	else
		return (0xffffff);
}

int				color_neg(int h)
{
	if (h > -1)
		return (0x79f8f8);
	if (h > -30)
		return (0x74d0f1);
	if (h > -150)
		return (0x357ab7);
	else
		return (0x003366);
}
