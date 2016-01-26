/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:20:13 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/27 00:39:19 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int argc, char **argv)
{
	DIR				*rep;
	struct dirent	*dir;
	t_dir			*list;
	struct stat		stats;
	t_dir			*first;

	if (argc >= 2)
	{
		list = NULL;
		first = list;
		if ((rep = opendir(argv[1])) == NULL)
			return (-1);
		while ((dir = readdir(rep)))
		{
			if (dir->d_name[0] != '.')
			{
				if ((stat(dir->d_name, &stats)) == -1)
					return (-1);
				ft_putendl(dir->d_name);
				add_link(list, stats, dir->d_name);
				printing(list);
				list = list->next;
			}
		}
	}
	return (0);
}
