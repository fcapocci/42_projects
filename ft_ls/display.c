/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:34:20 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/20 11:01:31 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printing(t_opt *optl, t_dir *start, t_dir *end)
{
	t_dir	*ptr;

	ptr = start;
	if (option_ok(optl, 'l') == 1 && start)
	{
		ft_putstr("total ");
		ft_putnbr(total_blk(start));
		ft_putchar('\n');
	}
	while ((option_ok(optl, 'r') == 1) ? end : start)
	{
		if (option_ok(optl, 'l') == 1)
			print_opt_l(ptr, (option_ok(optl, 'r') == 1) ? end : start);
		ft_putstr(hide_path(option_ok(optl, 'r') == 1 ? end->name
		: start->name));
		if ((((option_ok(optl, 'r') == 1) ? end->type : start->type) == 'l')
		&& (option_ok(optl, 'l') == 1))
			get_link(option_ok(optl, 'r') == 1 ? end->name : start->name);
		ft_putchar('\n');
		end = (option_ok(optl, 'r') == 1) ? end->prev : end;
		start = (option_ok(optl, 'r') == 0) ? start->next : start;
	}
}

void		print_file(t_opt *optl, t_dir *start)
{
	t_dir	*ptr;

	ptr = start;
	while (start)
	{
		if (option_ok(optl, 'l') == 1)
			print_opt_l(ptr, start);
		ft_putstr(start->name);
		if (start->type == 'l' && option_ok(optl, 'l') == 1)
			get_link(start->name);
		ft_putchar('\n');
		start = start->next;
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

void		illegal_option(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ls [-Ralrt] [file ...]");
}

void		get_link(char *file)
{
	char	buff[256];
	int		n;

	n = readlink(file, buff, 255);
	ft_putstr(" -> ");
	write(1, buff, n);
}
