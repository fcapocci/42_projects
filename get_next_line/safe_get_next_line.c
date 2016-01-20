/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:21:34 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/18 17:41:20 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		savebuffer(int const fd, char **save)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	ft_bzero(buff, BUFF_SIZE + 1);
	while (!ft_strchr(buff, '\n'))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) <= 0)
			return (ret);
		buff[ret] = '\0';
		if ((tmp = ft_strjoin(*save, buff)) == NULL)
			return (-1);
		ft_memdel((void**)save);
		*save = tmp;
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_files	files;
	char			*ptr;
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (files.save != fd)
	{
		files.save = fd;
		ft_memdel((void**)&files.buff);
	}
	if ((savebuffer(fd, &files.buff)) == -1)
		return (-1);
	if ((files.buff == NULL) || (ft_strlen(files.buff) == 0))
		return (0);
	ptr = ft_strchr(files.buff, '\n');
	*line = ft_strndup(files.buff, ptr - files.buff);
	tmp = ft_strsub(files.buff, ptr - files.buff + 1, ft_strlen(files.buff));
	ft_memdel((void**)&files.buff);
	files.buff = tmp;
	return (1);
}
