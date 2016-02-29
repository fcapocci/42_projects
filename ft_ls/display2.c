/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 22:16:11 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/29 18:21:53 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_path(char *dirname, int save, t_dir *flist)
{
	static int		loop;

	if (save > 1 && (loop > 0 || flist))
	{
		if (dirname[1] && dirname[0] == '/' && dirname[1] == '/')
			dirname++;
		ft_putchar('\n');
		ft_putstr(dirname);
		ft_putstr(":\n");
	}
	else if (save > 2 && (loop == 0 || flist))
	{
		if (dirname[1] && dirname[0] == '/' && dirname[1] == '/')
			dirname++;
		ft_putstr(dirname);
		ft_putstr(":\n");
	}
	loop++;
}

int			permis_denied(char *entity)
{
	char			*dirname;

	dirname = hide_path(entity);
	ft_putstr("ft_ls: ");
	ft_putstr(dirname);
	ft_putendl(": Permission denied");
	free(dirname);
	return (0);
}

void		print_error(char *entity, int fonction)
{
	char			*filename;

	if (fonction == 0 || fonction == 1)
	{
		filename = hide_path(entity);
		ft_putstr("ft_ls: ");
		ft_putstr(filename);
		ft_putendl(": No such file or directory");
		free(filename);
	}
	else
	{
		filename = hide_path(entity);
		ft_putstr("ft_ls: ");
		ft_putstr(filename);
		ft_putendl(": Input/output error");
		free(filename);
	}
}

void		print_tall(t_dir *start, t_dir *list)
{
	if (list->minor >= 0 && list->major >= 0)
	{
		padd_min_maj(start, list, 1);
		ft_putnbr(list->major);
		ft_putchar(',');
		padd_min_maj(start, list, 2);
		ft_putnbr(list->minor);
	}
	else
	{
		padd_tall(start, list);
		ft_putnbr(list->tall);
	}
}
