/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:07:45 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/08 18:38:54 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int		fd;
	int		i;
	char	*file;
	t_tlist	*tmp;
	t_tlist	*start;
	char	**map;
	char	**tab;
	int		size;

	if (argc != 2)
		return 0;

	fd = open(argv[1], O_RDONLY);
	ft_savefile(fd, &file);
	printf("file empty ? = %d\n", is_file_empty(file));
	printf("eof = %c\n", EOF);
	printf("bs0 = %c\n", '\0');
	printf("last char ='%c'\n", file[ft_strlen(file) - 1]);
	printf("format = %d\nsequence = %d\n", is_format_ok(file), is_sequence_ok(file));
	printf("chars ok = %d\nlen ok = %d\n", are_chars_ok(file), is_file_len_ok(file));
	tmp = save_tetris(file);
	tmp = ordering(tmp);
	printf("are tetri ok ? = %d\n", are_tetris_ok(tmp));
	tmp = rename_diez(tmp);
	start = tmp;
	/*while (tmp)
	{
		i = 0;
		while (i < 4)
			printf("%s\n", tmp->tetri[i++]);
		printf("\n");
		tmp = tmp->next;
	}*/
	tmp = start;
	printf("virtual_size = %d\n", virtual_size(len_lst(tmp)));
	map = create_map();
	//place_tetri(&map, tmp->tetri, 1, 0);
	//place_tetri(&map, tmp->next->tetri, 0, 0);
	printf("tetri letter = %c\n", getletter(tmp->tetri));
	//solve(&map, virtual_size(len_lst(tmp)), tmp);
	printf("%c\n", map[0][0]);


	printf("__ BEFORE BACKTRACK __\n");
	tab = NULL;
	size = virtual_size(len_lst(tmp));
	tmp = start;
	while (tab == NULL)
	{
		printf("size = %d\n", size);
		tab = backtrackit(map, size, tmp);
		size++;
	}
	printf("__ AFTER BACKTRACK __\n");
	i = 0;
	/*while (i < 40)
	{
		write(1, map[i++], 50);
		write(1, "\n", 1);
	}*/
	print_map(tab, size - 1);
	return (0);
}
