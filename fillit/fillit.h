/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:29:20 by vcastro-          #+#    #+#             */
/*   Updated: 2015/12/23 11:08:48 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 42
# define ERROR -1
# define SUCCESS 1
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct		s_tlist
{
	char			**tetri;
	struct s_tlist	*next;
}					t_tlist;

int					is_file_empty(char *file);
int					ft_savefile(int fd, char **file);
int					are_chars_ok(char *file);
int					is_file_len_ok(char *file);
int					is_sequence_ok(char *file);
int					is_format_ok(char *file);
t_tlist				*ft_create_elem(char *file);
t_tlist				*save_tetris(char *file);
int					order_h(char **tetri);
int					order_v(char **tetri);
char				**order_tetri_h(char **tetri);
char				**order_tetri_v(char **tetri);
t_tlist				*ordering(t_tlist *start);
int					is_tetri_ok(char *file, char **piece);
int					are_tetris_ok(t_tlist *list);
int					die(void);
char				**change_diez(char **tetri, int l);
t_tlist				*rename_diez(t_tlist *start);
char				**create_map(void);
char				**fill_map(char **map);
int					len_lst(t_tlist *start);
int					virtual_size(int ntetri);
int					is_tetri_writable(char **map, char **tetri, int i, int j);
int					place_tetri(char ***map, char **tetri, int i, int j);
int					solve(char ***map, int size, t_tlist *lst);
int					tetri_size_h(char **tetri);
int					tetri_size_v(char **tetri);
#endif
