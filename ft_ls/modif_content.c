/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:13:40 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/25 18:17:51 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*dating(const time_t *clock)
{
	char	*crt_date;
	char	*tmp;
	char	*tmp2;

	if ((long)(time(NULL) - (long)*clock) > 15780000)
	{
		tmp = ft_strsub(ctime(clock), 4, 7);
		tmp2 = ft_strsub(ctime(clock), 19, 5);
		crt_date = ft_strjoin(tmp, tmp2);
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&tmp2);
	}
	else
		crt_date = ft_strsub(ctime(clock), 4, 12);
	return (crt_date);
}

char		*hide_path(char *entity)
{
	char	*new;
	int		len;

	while (ft_strchr(entity, '/'))
		entity++;
	len = ft_strlen(entity);
	new = ft_strsub(entity, 0, len);
	return (new);
}

long		total_blk(t_dir *list)
{
	long	total;

	total = 0;
	while (list)
	{
		total += list->blksize;
		list = list->next;
	}
	return (total);
}

void		print_colors(char *s1, char *s2, char *s3)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
}

void		colors(t_opt *optl, char *name, char type, char *modes)
{
	if (op_ok(optl, 'G'))
		if (type == '-' && ((modes[8] == 'x') || (modes[5] == 'x')
		|| (modes[2] == 'x')))
			print_colors("\033[31m", name, "\033[0m");
		else if (type == 'd')
			print_colors("\033[1;36m", name, "\033[0m");
		else if (type == 'l')
			print_colors("\033[35m", name, "\033[0m");
		else if (type == 'c')
			print_colors("\033[0;34;43m", name, "\033[0m");
		else if (type == 'b')
			print_colors("\033[0;34;46m", name, "\033[0m");
		else if (type == 's')
			print_colors("\033[32m", name, "\033[0m");
		else
			ft_putstr(name);
	else
		ft_putstr(name);
}
