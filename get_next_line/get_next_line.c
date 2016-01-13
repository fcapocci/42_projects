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

int		savebuffer(int const fd, char **save)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = ft_strjoin((*save), buff);
		ft_memdel((void**)save);
		(*save) = tmp;
		if (!(*save))
			return (-1);
	}
	return (1);
}

char	*passline(char *buff)
{
	while (*buff != '\n' && *buff != '\0')
		buff++;
	if (*buff == '\n')
		buff++;
	return (buff);
}

int		get_next_line(int const fd, char **line)
{
	static t_files	files;
	char			*tmp;
	size_t			len;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (files.save != fd)
	{
		files.buff = NULL;
		files.save = fd;
	}
	if (!files.buff)
		if (savebuffer(fd, &files.buff) == -1)
			return (-1);
	tmp = ft_strchr(files.buff, '\n');
	if (ft_strlen(files.buff) == 0)
		return (0);
	len = tmp ? tmp - files.buff : ft_strlen(files.buff);
	(*line) = ft_strsub(files.buff, 0, len);
	if (!(*line))
		return (-1);
	files.buff = passline(files.buff);
	return (1);
}
