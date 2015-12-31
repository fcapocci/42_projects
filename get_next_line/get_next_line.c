/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:21:34 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/14 11:12:10 by fcapocci         ###   ########.fr       */
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
	static char	*buff;
	size_t		len;

	(*line) = NULL;
	if (!buff)
		if ((savebuffer(fd, &buff) == -1))
			return (-1);
	if (*buff != '\0')
	{
		len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n'));
		(*line) = ft_strsub(buff, 0, len);
		ft_putstr("line = ");
		ft_putendl((*line));
		passline(&buff);
		if (*buff != '\0')
			return (1);
	}
	return (0);
}
