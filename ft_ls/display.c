/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:34:20 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/10 12:18:51 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printing(t_opt *optl, t_dir *start, t_dir *end)
{
	t_dir	*ptr;

	ptr = start;
	if (!start->next || !end->prev)
		exit(0);
	if (option_ok(optl, 'l') == 1)
	{
		ft_putstr("total ");
		ft_putnbr(total_blk(start));
		ft_putchar('\n');
	}
	while ((option_ok(optl, 'r') == 1) ? end : start)
	{
		if (option_ok(optl, 'l') == 1)
			print_opt_l(ptr, (option_ok(optl, 'r') == 1) ? end : start);
		ft_putendl(hide_path(option_ok(optl, 'r') == 1 ? end->name
		: start->name));
		end = (option_ok(optl, 'r') == 1) ? end->prev : end;
		start = (option_ok(optl, 'r') == 0) ? start->next : start;
	}
}

void		print_opt_l(t_dir *start, t_dir *list)
{
	ft_putchar(list->type);
	ft_putstr(list->modes);
	padd_nblink(start, list);
	ft_putnbr(list->nblink);
	ft_putchar(' ');
	ft_putstr(list->owner);
	padd_owner(start, list);
	ft_putstr(list->grp);
	padd_grp(start, list);
	padd_tall(start, list);
	ft_putnbr(list->tall);
	ft_putchar(' ');
	ft_putstr(list->date);
	ft_putchar(' ');
}

void		not_arg_printing(char *arg)
{
	ft_putstr("ls: ");
	ft_putstr(arg);
	ft_putstr(": ");
	ft_putendl("No such file or directory");
}

void		illegal_option(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ls [-lrtaR] [file ...]");
}
