/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:21:34 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/13 14:03:20 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		savebuffer(int const fd, char **save, char ***line)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	ret = 1;
	while (!ft_strchr(buff, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = ft_strjoin((*save), buff);
		ft_memdel((void**)save);
		(*save) = tmp;
		if (!(*save))
			return (-1);
	}
	(**line) = (*save);
	if (!(**line))
		return (-1);
	else if (ret == 0)
		return (0);
	else
		return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_files	files;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	files.buff = NULL;
	if (files.save != fd)
		files.save = fd;
	return (savebuffer(fd, &files.buff, &line));
}
