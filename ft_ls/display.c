/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:34:20 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/27 17:01:05 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printing(t_dir *list)
{
	while (list != NULL)
	{
		ft_putchar(list->type);
		ft_putstr(list->modes);
		ft_putstr("  ");
		ft_putnbr(list->nblink);
		ft_putchar(' ');
		ft_putstr(list->owner);
		ft_putstr("  ");
		ft_putstr(list->grp);
		ft_putstr("  ");
		ft_putnbr(list->tall);
		ft_putchar(' ');
		ft_putstr(list->date);
		ft_putchar(' ');
		ft_putendl(list->name);
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
