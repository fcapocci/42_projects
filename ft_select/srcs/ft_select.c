/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 10:08:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/08 13:19:44 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

static int		init_term_env(struct termios *term)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putendl("missing TERM env");
		return (ERR);
	}
	if (tgetent(NULL, name_term) == -1)
		return (ERR);
	if (tcgetattr(0, term) == -1)
		return (ERR);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (ERR);
	return (OK);
}
static int		res_term_env(struct termios *term)
{
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (ERR);
	return (OK);
}

static int		looper(struct termios term, t_lst *lst)
{
	char			buff[3];

	while (1)
	{
		print_argv(lst);
		read(0, buff, 3);
		if (buff[0] == 27)
			ft_putendl("c'est une flech");
		if (buff[0] == 4)
		{
			ft_putendl("ctrl-D on quit");
			break ;
		}
	}
	return (OK);
}

int				ft_select(int argc, char **argv)
{
	t_lst			*lst;
	struct termios	term;

	if (init_term_env(&term) == ERR)
		return (ERR);
	if ((lst = init_lst(argc, argv)) == NULL)
		return (ERR);
	looper(term, &(*lst));
	free_lst(lst);
	res_term_env(&term);
	return (OK);
}
