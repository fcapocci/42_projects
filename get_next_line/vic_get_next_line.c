/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:07:10 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/04 17:02:43 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vic_get_next_line.h"
#include <fcntl.h>

int		savefile(int fd, char **file)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*adr;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (!(adr = ft_strjoin(*file, buf)))
			return (-1);
		ft_memdel((void**)file);
		(*file) = adr;
	}
	return (1);
}

char	*pass_line(char *file)
{
	while (*file != '\n' && *file != '\0')
		file++;
	if (*file == '\n')
		file++;
	return (file);
}

int		get_next_line(int const fd, char **line)
{
	static t_files	files;
	char			*tmp;
	int				len;

	(*line) = (void*)0;
	if (files.filedes != fd)
	{
		files.file = (void*)0;
		files.filedes = fd;
	}
	if (!(files.file))
		if (savefile(fd, &(files.file)) == -1)
			return (-1);
	tmp = ft_strchr(files.file, '\n');
	if (ft_strlen(files.file) == 0)
		return (0);
	len = (tmp ? tmp - files.file : ft_strlen(files.file));
	(*line) = ft_strsub(files.file, 0, len);
	if (!(*line))
		return (-1);
	files.file = pass_line(files.file);
	return (1);
}
