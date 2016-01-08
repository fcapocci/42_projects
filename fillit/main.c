/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:27:26 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/08 16:13:20 by vcastro-         ###   ########.fr       */
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

void	print_fillit(char **map, t_tlist *pieces)
{
	char	**tab;
	int		size;

	tab = (void*)0;
	size = virtual_size(len_lst(pieces));
	while (tab == (void*)0)
	{
		tab = backtrackit(map, size, pieces);
		size++;
	}
	print_map(tab, size - 1);
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
	tmp = rename_diez(tmp);
	map = create_map();
	print_fillit(map, tmp);
	return (0);
}
