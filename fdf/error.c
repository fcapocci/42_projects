/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:19:13 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/17 13:19:25 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			usage_error(int argc)
{
	if (argc != 2)
		ft_putendl("Usage : ./fdf <filename>");
}

void			file_invalid(char *name)
{
	char		*tmp;

	if ((tmp = ft_strrchr(name, '/')) != NULL)
		tmp++;
	else
		tmp = name;
	ft_putstr("This file is not conform: ");
	ft_putendl(tmp);
}
