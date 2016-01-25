/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_modes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:57:22 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/25 19:18:05 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*take_modes(mode_t st_mode)
{
	char	*s;

	if ((s = (char*)ft_memalloc(10)) == NULL)
		return (NULL);
	s[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	s[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	s[2] = (st_mode & S_IXUSR) ? 'x' : '-';
	s[3] = (st_mode & S_IRGRP) ? 'r' : '-';
	s[4] = (st_mode & S_IWGRP) ? 'w' : '-';
	s[5] = (st_mode & S_IXGRP) ? 'x' : '-';
	s[6] = (st_mode & S_IROTH) ? 'r' : '-';
	s[7] = (st_mode & S_IWOTH) ? 'w' : '-';
	s[8] = (st_mode & S_IXOTH) ? 'x' : '-';
	return (s);
}

char	take_type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISLNK(st_mode))
		return ('l');
	return (0);
}
