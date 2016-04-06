/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typefile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:53:10 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/06 15:23:48 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

char			ft_typefile(char *path)
{
	struct stat		stats;

	if ((stat(path, &stats)) == -1)
		return (0);
	if (S_ISREG(stats.st_mode))
		return ('-');
	else if (S_ISDIR(stats.st_mode))
		return ('d');
	else if (S_ISFIFO(stats.st_mode))
		return ('p');
	else if (S_ISCHR(stats.st_mode))
		return ('c');
	else if (S_ISBLK(stats.st_mode))
		return ('b');
	else if (S_ISSOCK(stats.st_mode))
		return ('s');
	else if (S_ISLNK(stats.st_mode))
		return ('l');
	return (0);
}
