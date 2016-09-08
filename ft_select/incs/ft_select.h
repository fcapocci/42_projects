/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:36:07 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/27 16:00:58 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>
# include <signal.h>

# define CD		(buff[0] ==   4 && buff [1] ==  0 && buff[2] ==  0)
# define TAB	(buff[0] ==   9 && buff [1] ==  0 && buff[2] ==  0)
# define ESC	(buff[0] ==  27 && buff [1] ==  0 && buff[2] ==  0)
# define DEL	(buff[0] == 127 && buff [1] ==  0 && buff[2] ==  0)
# define DEL2	(buff[0] == 126 && buff [1] ==  0 && buff[2] ==  0)
# define SPACE	(buff[0] ==  32 && buff [1] ==  0 && buff[2] ==  0)
# define RET	(buff[0] ==  10 && buff [1] ==  0 && buff[2] ==  0)
# define UP		(buff[0] ==  27 && buff [1] == 91 && buff[2] == 65)
# define DOWN	(buff[0] ==  27 && buff [1] == 91 && buff[2] == 66)
# define RIGHT	(buff[0] ==  27 && buff [1] == 91 && buff[2] == 67)
# define LEFT	(buff[0] ==  27 && buff [1] == 91 && buff[2] == 68)


# define ERR   -1
# define OK		0
# define PRINT	1

typedef struct			s_lst
{
	char				*name;
	size_t				len_name;
	int					type;
	int					selected;
	size_t				num;
	struct s_lst		*prev;
	struct s_lst		*next;
}						t_lst;

typedef struct		s_term
{
	int					nb_word_col;
	t_lst				*lst;
	t_lst				*curs;
	struct termios		term;
}						t_term;

int						ft_select(int argc, char **argv);

t_lst					*init_lst(int argc, char **argv);

void					print_status(void);
void					print_sign(int signal);

void					print_argv(int nb);

void					print_selected(t_lst *lst);

void					nb_select(int place, t_lst *lst, t_lst *start);

int						space_key(t_lst **curs);
int						del_key(t_lst **lst, t_lst **curs);
int						event_key(char *buff);

int						move_up(t_lst **curs);
int						move_down(t_lst **curs);
int						move_right(t_lst **curs, int word_col);
int						move_left(t_lst **curs, int word_col);

t_term					*get_addr(void);
void					error(char *s);
int						ft_ouct(int c);
int						exe_cmd(char *s);
int						move_curs(int x, int y);

void					free_lst(t_lst *lst);
void					stop(int nb);

# endif
