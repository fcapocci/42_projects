/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 10:08:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/09/08 16:50:21 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_select.h"

static int		init_term_env(t_term *glob)
{
	char			*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putendl("missing TERM env");
		return (ERR);
	}
	if (tgetent(NULL, name_term) == -1)
		return (ERR);
	if (tcgetattr(0, &(glob->term)) == -1)
		return (ERR);
	exe_cmd("ti");
	exe_cmd("vi");
	glob->term.c_lflag &= ~(ICANON | ECHO);
	glob->term.c_cc[VMIN] = 1;
	glob->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(glob->term)) == -1)
		return (ERR);
	return (OK);
}

static int		res_term_env(t_term *glob)
{
	glob->term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &(glob->term)) == -1)
		return (ERR);
	exe_cmd("te");
	exe_cmd("ve");
	return (OK);
}

static int		looper(t_term *glob)
{
	char			buff[4];
	int				ret;

	glob->curs = glob->lst;
	while (1)
	{
		print_argv(0);
		ft_bzero(buff, 3);
		read(0, buff, 3);
		if ((ret = event_key(buff)))
			return (ret == ERR ? ERR : PRINT);
	}
	return (OK);
}

int				ft_select(int argc, char **argv)
{
	int				ret;
	t_term			*glob;

	if ((glob = get_addr()) == NULL)
		return (ERR);
	if (init_term_env(glob) == ERR)
		return (ERR);
	if ((glob->lst = init_lst(argc, argv)) == NULL)
		return (ERR);
	signal(SIGWINCH, print_argv);
	ret = looper(glob);
	res_term_env(glob);
	if (ret == PRINT)
		print_selected(glob->lst);
	stop(0);
	return (OK);
}
