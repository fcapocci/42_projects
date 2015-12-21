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
		ft_putstr("buff content --> ");
		ft_putstr(buff);
		ft_putstr("\nsave content --> ");
		ft_putendl(*save);
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
	len = ft_strlen(ft_strchr(buff, '\n'));
	ft_putstr("len value --> ");
	ft_putnbr(len);
	ft_putchar('\n');
	(*line) = ft_strsub(buff, 0, len);
	passline(&buff);
	if (*line == '\0')
		return (0);
	return (1);
}
