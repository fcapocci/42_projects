/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/07 04:36:53 by fcapocci         ###   ########.fr       */
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

	if (argc >= 1 || argv)
	{
		while (42)
		{
			prompt();
			get_next_line(0, &line);
			if (!ft_strcmp(line, "exit"))
				exit(0);
			if (get_cmd(line, env) == -1)
				exit(0);
			//if (get_builtins() == -1)
			//	exit(0);
		}
	}
	return (0);
}
