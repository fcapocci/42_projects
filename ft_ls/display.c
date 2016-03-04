/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:34:20 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/04 11:42:15 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		printing(t_opt *optl, t_dir *start, t_dir *end)
{
	t_dir	*ptr;

	ptr = start;
	if (op_ok(optl, 'l') == 1 && start)
	{
		ft_putstr("total ");
		ft_putnbr(total_blk(start));
		ft_putchar('\n');
	}
	while ((op_ok(optl, 'r') == 1) ? end : start)
	{
		if ((op_ok(optl, 'l')) || (op_ok(optl, 'g')) || (op_ok(optl, 'o')))
			print_opt_l(optl, ptr, (op_ok(optl, 'r') == 1) ? end : start);
		colors(optl, hide_path(op_ok(optl, 'r') == 1 ? end->name
		: start->name), (op_ok(optl, 'r') ? end->type : start->type),
		op_ok(optl, 'r') ? end->modes : start->modes);
		if ((((op_ok(optl, 'r') == 1) ? end->type : start->type) == 'l')
		&& (op_ok(optl, 'l') == 1))
			get_link(op_ok(optl, 'r') == 1 ? end->name : start->name);
		ft_putchar('\n');
		end = (op_ok(optl, 'r') == 1) ? end->prev : end;
		start = (op_ok(optl, 'r') == 0) ? start->next : start;
	}
}

void		print_file(t_opt *optl, t_dir *start)
{
	t_dir	*ptr;

	ptr = start;
	while (start)
	{
		if (op_ok(optl, 'l') == 1)
			print_opt_l(optl, ptr, start);
		colors(optl, start->name, start->type, start->modes);
		if (start->type == 'l' && op_ok(optl, 'l') == 1)
			get_link(start->name);
		ft_putchar('\n');
		start = start->next;
	}
}

void		print_opt_l(t_opt *optl, t_dir *start, t_dir *list)
{
	ft_putchar(list->type);
	ft_putstr(list->modes);
	ft_putchar(list->acl);
	padd_nblink(start, list);
	ft_putnbr(list->nblink);
	ft_putchar(' ');
	if (!op_ok(optl, 'g'))
	{
		ft_putstr(list->owner);
		padd_owner(start, list);
	}
	if (!op_ok(optl, 'o'))
	{
		ft_putstr(list->grp);
		padd_grp(start, list);
	}
	print_tall(start, list);
	ft_putchar(' ');
	ft_putstr(list->date);
	ft_putchar(' ');
}

void		illegal_option(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [GRafglnort] [file ...]\n");
}

void		get_link(char *file)
{
	char	buff[256];
	int		n;

	n = readlink(file, buff, 255);
	ft_putstr(" -> ");
	write(1, buff, n);
}
