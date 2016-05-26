/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:14:46 by fcapocci          #+#    #+#             */
/*   Updated: 2016/05/26 13:08:37 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int				next_line_val(t_data *d_list, int y, int x)
{
	while (d_list)
	{
		if (d_list->x == x && d_list->y == (y + 1))
			return (d_list->h);
		d_list = d_list->next;
	}
	return (-20000);
}

t_data			*creat_elem(int x, int y, int h)
{
	t_data		*elem;

	if ((elem = ft_memalloc(sizeof(t_data))) == NULL)
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->h = h;
	elem->next = NULL;
	return (elem);
}

t_data			*creat_list(t_data *data_list, char **d_tab, int y)
{
	t_data		*tmp_list;
	size_t		x;

	tmp_list = data_list;
	x = 0;
	while (x != len_y(d_tab))
	{
		if (data_list == NULL)
			if (!(data_list = tmp_list = creat_elem(x, y, ft_atoi(d_tab[x]))))
				return (NULL);
		if (tmp_list)
		{
			while (tmp_list->next)
				tmp_list = tmp_list->next;
			if (!(tmp_list->next = creat_elem(x, y, ft_atoi(d_tab[x]))))
				return (NULL);
		}
		x++;
	}
	return (data_list);
}

t_data			*pars(char *files, int ret)
{
	t_data		*data_list;
	char		**data_tab;
	char		*line;
	int			fd;
	int			y;

	if ((fd = open(files, O_RDONLY)) == -1)
		return (NULL);
	data_list = NULL;
	line = NULL;
	y = 0;
	while (ret > 0)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (NULL);
		if ((data_tab = ft_strsplit(line, ' ')) == NULL)
			break ;
		if ((data_list = creat_list(data_list, data_tab, y)) == NULL)
			return (NULL);
		y++;
		ft_memdel((void**)&line);
		ft_free_strsplit(&data_tab);
	}
	close(fd);
	return (data_list);
}
