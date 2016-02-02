/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 17:38:23 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/01 19:38:26 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*int		app_option(t_dir **list, t_opt *optl)
{
	return (0);
}*/

int		read_dir(t_dir **list, int argc, char **argv)
{
	DIR				*rep;
	struct dirent	*dir;
	struct stat		stats;
	t_dir			*slist;

	slist = (*list);
	if (argc >= 2)
	{
		while (argv[1][0] == '-')
			(*argv)++;
		if ((rep = opendir(argv[1])) == NULL)
		ft_putendl(argv[1]);
			exit(-1);
		while ((dir = readdir(rep)))
		{
			if (dir->d_name[0] != '.')
			{
				if ((stat(ft_strjoin(ft_strjoin(argv[1], "/"), dir->d_name)
				, &stats)) == -1)
					return (-1);
				if ((slist = add_link(slist, stats, dir->d_name)) == NULL)
					return (-1);
				if (!(*list))
					(*list) = slist;
			}
		}
	}
	return (0);
}
