/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:27:26 by fcapocci          #+#    #+#             */
/*   Updated: 2015/12/17 14:23:56 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		are_entries_ok(char *file)
{
	if ((is_file_empty(file)) == ERROR)
		return (ERROR);
	if ((are_chars_ok(file)) == ERROR)
		return (ERROR);
	if ((is_file_len_ok(file)) == ERROR)
		return (ERROR);
	if ((is_sequence_ok(file)) == ERROR)
		return (ERROR);
	if ((is_format_ok(file)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int		die(void)
{
	write(1, "error\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*file;
	char	**map;
	t_tlist	*tmp;

	if (argc != 2)
		return (die());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (die());
	if ((ft_savefile(fd, &file)) == ERROR)
		return (die());
	if ((are_entries_ok(file)) == ERROR)
		return (die());
	tmp = save_tetris(file);
	tmp = ordering(tmp);
	if ((are_tetris_ok(tmp)) == ERROR)
		return (die());
	return (0);
}
