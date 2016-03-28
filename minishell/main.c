/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/28 18:37:54 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		prompt(void)
{
	char		mem[256];

	getcwd(mem, 256);
	ft_putstr("\033[32m");
	ft_putstr(mem);
	ft_putstr("\033[0m > ");
}

int			main(int argc, char **argv, char **env)
{
	char		*line;
	t_env		*vlist;
	int			r;

	if (argc < 1 || !argv)
		return (0);
	if (!(vlist = creat_list(env)))
		return (-1);
	while (42)
	{
		prompt();
		get_next_line(0, &line);
		if (ft_strcmp(line, "\0"))
		{
			if ((r = get_builtins(line)) != 0)
				(r < 0 ? quit(&vlist, &line) : exe_builtins(line, &vlist));
			else
			{
				if ((r = get_cmd(line, vlist)) <= 0)
					(r == 0 ? no_cmd(sup_tab(line)) : quit(&vlist, &line));
			}
		}
		ft_memdel((void**)&line);
	}
	return (0);
}
