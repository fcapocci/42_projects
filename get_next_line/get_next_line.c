/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:21:34 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/20 18:44:13 by fcapocci         ###   ########.fr       */
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

static int		add_maill(int fd, t_files **start, t_files **files)
{
	t_files			*new;

	if ((new = (t_files*)ft_memalloc(sizeof(t_files))) == NULL)
		return (-1);
	if ((savebuffer(fd, &new->buff)) == -1)
	{
		ft_memdel((void**)&new);
		return (-1);
	}
	if (new->buff == NULL)
	{
		ft_memdel((void**)&new);
		return (0);
	}
	new->save = fd;
	new->next = (*start);
	(*start) = new;
	(*files) = new;
	return (1);
}

static char		*save_line(char **buff)
{
	char			*new_line;
	char			*ptr;
	char			*tmp;

	if ((ptr = ft_strchr((*buff), '\n')) == NULL)
		new_line = ft_strdup((*buff));
	else
		new_line = ft_strsub((*buff), 0, ptr - (*buff));
	if ((tmp = ft_strsub((*buff), (ptr == NULL) ? ft_strlen(new_line) :
		ft_strlen(new_line) + 1, ft_strlen(*buff))) == NULL)
		return (NULL);
	ft_memdel((void**)buff);
	(*buff) = tmp;
	return (new_line);
}

int				get_next_line(int const fd, char **line)
{
	static t_files	*start_files;
	t_files			*files;
	int				retour;

	if (fd < 0 || line == NULL)
		return (-1);
	files = start_files;
	while (files != NULL)
	{
		if (files->save == fd)
			break ;
		files = files->next;
	}
	if (files == NULL)
		if ((retour = add_maill(fd, &start_files, &files)) <= 0)
			return ((retour == 0) ? 0 : -1);
	if ((savebuffer(fd, &files->buff)) == -1)
		return (-1);
	if ((files->buff == NULL) || (ft_strlen(files->buff) == 0))
		return (0);
	if (((*line) = save_line(&files->buff)) == NULL)
		return (-1);
	return (1);
}
