/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/01 20:36:13 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		prompt(void)
{
	char		*str;
	char		*tmp;

	str = ft_strnew(255);
	getcwd(str, 255);
	tmp = str;
	if (str[0] == '/' && str[1] != '\0')
		while (ft_strchr(str, '/'))
			str++;
	ft_putstr("\033[36m");
	ft_putstr("[minishell]=> ");
	ft_putstr("\033[31m");
	ft_putstr(str);
	ft_putstr("\033[33m > ");
	ft_putstr("\033[0m");
	ft_memdel((void**)&tmp);
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
				if ((r = get_cmd(line, vlist)) == -1)
					quit(&vlist, &line);
			}
		}
		ft_memdel((void**)&line);
	}
	return (0);
}
