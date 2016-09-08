/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:45:49 by fcapocci          #+#    #+#             */
/*   Updated: 2016/09/08 16:57:39 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"
#include <sys/ioctl.h>

#define CURS "\033[4m"
#define SELECT "\033[7m"
#define C_SELC "\033[7;4m"
#define RES "\033[0m"

static size_t		bigger_in_list(t_lst *lst)
{
	size_t				len;
	t_lst				*start;

	len = 0;
	start = NULL;
	while (lst != start)
	{
		start = !start ? lst : start;
		len = lst->len_name > len ? lst->len_name : len;
		lst = lst->next;
	}
	return (len);
}

static int			get_window_size(struct winsize *win)
{
	if (ioctl(0, TIOCGWINSZ, win) < 0)
		return (ERR);
	return (OK);
}

static void			put_word(char *s)
{
	ft_putstr(s);
	ft_putstr(RES);
}

static int			print_col(t_term *glob, struct winsize win,
					t_lst **start, int loop)
{
	int					i;
	size_t				bigger;
	size_t				savver;
	size_t				limit;

	i = 0;
	bigger = bigger_in_list(glob->lst);
	savver = loop > 1 ? (bigger * (loop - 1) + (2 * (loop - 1))) : 0;
	if ((limit = (loop ? ((bigger * 2) + 2) : bigger) + savver) > win.ws_col)
		return (ERR);
	while (i < (win.ws_row - 4) && glob->lst != *start)
	{
		*start = (*start == NULL) ? glob->lst : *start;
		if (glob->lst == glob->curs)
			ft_putstr(glob->lst->selected == 1 ? C_SELC : CURS);
		else
			ft_putstr(glob->lst->selected == 1 ? SELECT : RES);
		move_curs(loop ? (bigger + 2 + (savver)) : 0, i);
		put_word(glob->lst->name);
		glob->lst = glob->lst->next;
		i++;
	}
	return (OK);
}

void				print_argv(int loop)
{
	t_lst				*start;
	struct winsize		win;
	t_term				*glob;

	glob = get_addr();
	get_window_size(&win);
	glob->nb_word_col = win.ws_row;
	exe_cmd("cl");
	loop = 0;
	start = NULL;
	while (glob->lst != start)
	{
		if (print_col(glob, win, &start, loop))
		{
			glob->lst = start ? start : glob->lst;
			return (error("Error window size"));
		}
		loop++;
	}
	nb_select(win.ws_row, glob->lst, NULL);
}
