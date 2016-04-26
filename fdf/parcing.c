/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:14:46 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/26 14:41:10 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

t_data			*creat_elem(int x, int y, char c)
{
	t_data		*elem;

	if ((elem = ft_memalloc(sizeof(t_data))) == NULL)
		return (NULL);
	elem->x = x;
	elem->y = y;
	elem->h = c - 48;
	elem->next = NULL;
	return (elem);
}

t_data			*creat_list(char **data_tab)
{
	t_data		*data_list[2];
	int			x;
	int			y;

	data_list[0] = NULL;
	data_list[1] = data_list[0];
	y = 0;
	while (*data_tab)
	{
		x = 0;
		while (**data_tab)
		{
			if ((data_list[0] = creat_elem(x, y, **data_tab)) == NULL)
				return (NULL);
			data_list[0] = data_list[0]->next;
			(*data_tab)++;
			x++;
		}
		data_tab++;
		y++;
	}
	return (data_list[1]);
}

t_data			*pars(char *files)
{
	t_data		*data_list;
	char		**data_tab;
	char		*line;
	int			fd;
	int			ret;

	if ((fd = open(files, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	while (ret != 0)
		ret = get_next_line(fd, &line);
	close(fd);
	if ((data_tab = ft_strsplit(line, '\n')) == NULL)
			return (NULL);
	if ((data_list = creat_list(data_tab)) == NULL)
		return (NULL);
	ft_free_strsplit(&data_tab);
	return (data_list);
}
