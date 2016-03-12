/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/12 03:35:48 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		prompt(void)
{
	ft_putstr("\033[32m");
	ft_putstr("minishell");
	ft_putstr("\033[0m > ");
}

int			main(int argc, char **argv, char **env)
{
	char		*line;
	t_env		*vlist;
	int			r;

	if (argc >= 1 || argv)
	{
		while (42)
		{
			if (!(vlist = creat_list(env)))
				return (-1);
			prompt();
			get_next_line(0, &line);
			if (ft_strcmp(line, "\0"))
			{
				if (!ft_strcmp(line, "exit"))
					quit(&vlist, &line);
				if ((r = get_cmd(line, vlist)) <= 0)
					(r == 0 ? no_cmd(line) : quit(&vlist, &line));
			}
		}
	}
	return (0);
}
