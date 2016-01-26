/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:34:20 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/26 14:48:17 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printing(t_dir *list)
{
	while (list)
	{
		ft_putchar(list->type);
		ft_putchar(' ');
		ft_putstr(list->modes);
		ft_putchar(' ');
		ft_putnbr(list->nblink);
		ft_putchar(' ');
		ft_putstr(list->owner);
		ft_putchar(' ');
		ft_putstr(list->grp);
		ft_putchar(' ');
		ft_putnbr(list->tall);
		ft_putchar(' ');
		ft_putstr(list->date);
		ft_putchar(' ');
		ft_putstr(list->name);
		ft_putchar(' ');
		list = list->next;
	}
}

void		not_arg_printing(char *arg)
{
	ft_putstr("ls: ");
	ft_putstr(arg);
	ft_putstr(": ");
	ft_putendl("No such file or directory");
}
