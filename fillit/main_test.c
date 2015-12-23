/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:07:45 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/23 15:23:20 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, const char *argv[])
{
	int		fd;
	int		i;
	char	*file;
	t_tlist	*tmp;
	t_tlist	*start;
	char	**map;

	if (argc != 2)
		return 0;

	fd = open(argv[1], O_RDONLY);
	ft_savefile(fd, &file);
	printf("file empty ? = %d\n", is_file_empty(file));
	printf("format = %d\nsequence = %d\n", is_format_ok(file), is_sequence_ok(file));
	printf("chars ok = %d\nlen ok = %d\n", are_chars_ok(file), is_file_len_ok(file));
	tmp = save_tetris(file);
	tmp = ordering(tmp);
	printf("are tetri ok ? = %d\n", are_tetris_ok(tmp));
	tmp = rename_diez(tmp);
	start = tmp;
	while (tmp)
	{
		i = 0;
		while (i < 4)
			printf("%s\n", tmp->tetri[i++]);
		printf("\n");
		tmp = tmp->next;
	}
	tmp = start;
	printf("virtual_size = %d\n", virtual_size(len_lst(tmp)));
	map = create_map();
	printf("tetri size_h = %d\n", tetri_size_h(tmp->tetri));
	printf("tetri size_v = %d\n", tetri_size_v(tmp->tetri));
	solve(&map, virtual_size(len_lst(tmp)), tmp);
	i = 0;
	while (i < 30)
	{
		write(1, map[i++], 30);
		write(1, "\n", 1);
	}
	return (0);
}
