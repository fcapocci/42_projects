/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:34:10 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/13 14:52:09 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	struct stat		stats;

	if (argc == 2)
	{
		if ((stat(argv[1], &stats)) == -1)
			return (-1);
		printf("Nom: %s\n", argv[1]);
		printf("Type: %c\n", take_type(stats.st_mode));
		printf("Modes: %s\n", take_modes(stats.st_mode));
		printf("Nombre de liens: %d\n", stats.st_nlink);
		printf("Proprietaire: %s\n", getpwuid(stats.st_uid)->pw_name);
		printf("Groupe: %s\n", getgrgid(stats.st_gid)->gr_name);
		printf("Taille: %lld\n", stats.st_size);
		printf("Date de derniere modification: %s\n", ctime(&(stats.st_mtime)));
	}
	return (0);
}
