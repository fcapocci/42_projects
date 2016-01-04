/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:21:34 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/04 12:18:00 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		savebuffer(int const fd, char **save)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		(*save) = ft_strjoin((*save), buff);
		if (!(*save))
			return (-1);
	}
	return (1);
}

void	passline(char **buff)
{
	while (**buff != '\n' && **buff != '\0')
		(*buff)++;
	if (**buff == '\n')
		(*buff)++;
}

int		get_next_line(int const fd, char **line)
{
	static t_files	files;
	size_t		len;

	if (files.save != fd)
	{
		files.save = fd;
		files.buff = NULL;
	}
	if (!files.buff)
		if ((savebuffer(fd, &files.buff) == -1))
			return (-1);
	if (*files.buff == '\0')
		return (0);
	len = ft_strlen(files.buff) - ft_strlen(ft_strchr(files.buff, '\n'));
	(*line) = ft_strsub(files.buff, 0, len);
	passline(&files.buff);
	if (*files.buff == '\0')
		return (0);
	return (1);
}
