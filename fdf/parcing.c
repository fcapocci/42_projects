/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:14:46 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/26 12:11:48 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

char			**pars(char *files)
{
	char		**data_tab;
	char		*line;
	int			fd;
	int			ret;

	if ((fd = open(files, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	while (ret != 0)
		ret = get_next_line(fd, &line);
	if ((data_tab = ft_strsplit(line, '\n')) == NULL)
			return (NULL);
	return (data_tab);
}
