/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 17:20:13 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/27 18:15:08 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	DIR				*rep;
	struct dirent	*dir;
	t_dir			*list[2];
	struct stat		stats;

	if (argc >= 2)
	{
		if ((rep = opendir(argv[1])) == NULL)
			exit(-1);
		while ((dir = readdir(rep)))
		{
			if (dir->d_name[0] != '.')
			{
				if ((stat(ft_strjoin(ft_strjoin(argv[1], "/"), dir->d_name)
				, &stats)) == -1)
					return (-1);
				list[0] = add_link(list[0], stats, dir->d_name);
				if (!list[1])
					list[1] = list[0];
			}
		}
		printing(list[1]);
	}
	return (0);
}
