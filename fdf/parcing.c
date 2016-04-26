/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:14:46 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/26 21:28:38 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

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

t_data			*creat_list(char **data_tab, int y)
{
	t_data		*data_list[2];
	size_t			x;

	data_list[0] = NULL;
	data_list[1] = NULL;
	x = 0;
	while (x != len_y(data_tab))
	{
		if (data_list[0] == NULL)
		{
			if (!(data_list[0] = creat_elem(x, y, ft_atoi(data_tab[x]))))
				return (NULL);
			if (data_list[1] == NULL)
				data_list[1] = data_list[0];
		}
		else
			if (!(data_list[0]->next = creat_elem(x, y, ft_atoi(data_tab[x]))))
				return (NULL);
		data_list[0] = data_list[0]->next;
		x++;
	}
	return (data_list[1]);
}

t_data			*pars(char *files)
{
	t_data		*data_list;
	char		**data_tab;
	char		*line;
	int			fd;
	int			y;

	if ((fd = open(files, O_RDONLY)) == -1)
		return (NULL);
	y = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if ((data_tab = ft_strsplit(line, ' ')) == NULL)
			return (NULL);
		if ((data_list = creat_list(data_tab, y)) == NULL)
			return (NULL);
		y++;
		ft_free_strsplit(&data_tab);
	}
	close(fd);
	return (data_list);
}
