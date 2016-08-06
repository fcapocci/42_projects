/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:45:49 by fcapocci          #+#    #+#             */
/*   Updated: 2016/08/06 22:25:30 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"
#include <sys/ioctl.h>

#define CURS "\033[4m"
#define SELECT "\033[7m"
#define C_SELC "\033[7;4m"
#define RES "\033[0m"

static int			get_window_size(struct winsize *win)
{
	if (ioctl(0, TIOCGWINSZ, win) < 0)
		return (ERR);
	return (OK);
}

static void		put_word(char *s)
{
	ft_putstr(s);
	ft_putstr(RES);
}

static void		print_col(t_lst **lst, t_lst **curs, struct winsize win, t_lst
				**start, size_t *bigger)
{
	int					i;

	i = 1;
	while (i < win.ws_row && *lst != *start)
	{
		*start = (*start == NULL) ? *lst : *start;
		*bigger = (*lst)->len_name > *bigger ? (*lst)->len_name : *bigger;
		if (*lst == *curs)
			ft_putstr((*lst)->selected == 1 ? C_SELC : CURS);
		else
			ft_putstr((*lst)->selected == 1 ? SELECT : RES);
		put_word((*lst)->name);
		exe_cmd("do");
		*lst = (*lst)->next;
		i++;
	}
}

void			print_argv(t_lst *lst, t_lst *curs)
{
	t_lst				*start;
	struct winsize		win;
	size_t				bigger;
	size_t				decalage;

	get_window_size(&win);
	exe_cmd("cl");
	start = NULL;
	bigger = 1;
	decalage = 0;
	ft_putstr("nb de ligne: ");
	ft_putnbr(win.ws_row);
	ft_putchar('\n');
	ft_putstr("nb de colones: ");
	ft_putnbr(win.ws_col);
	ft_putchar('\n');
	while (lst != start)
	{
		print_col(&lst, &curs, win, &start, &bigger);
		move_curs(bigger + 2 + decalage, 0);
		decalage = bigger;
	}
}
