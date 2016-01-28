/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:46:24 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/25 11:33:46 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	DIR				*rep;
	struct dirent	*dir;

	if (argc >= 2)
	{
		if ((rep = opendir(argv[1])) == NULL)
			return (-1);
		while ((dir = readdir(rep)))
			if (dir->d_name[0] != '.')
				printf("%s\n",dir->d_name);
	}
	return 0;
}
