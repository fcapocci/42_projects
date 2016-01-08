/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:19:47 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/08 18:48:03 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_savefile(int fd, char **file)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*adr;

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(adr = ft_strjoin(*file, buf)))
			return (ERROR);
		ft_memdel((void**)file);
		(*file) = adr;
	}
	if (buf[0] == '#' || buf[0] == '.')
	{
		(*file)[ft_strlen((*file))] = '\n';
		(*file) = ft_strjoin(*file, "\0");
	}
	return (SUCCESS);
}
