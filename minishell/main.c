/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/02 03:35:07 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		prompt(t_env *vlist)
{
	char		*str;
	char		*tmp;
	char		*home;

	home = NULL;
	str = ft_strnew(255);
	getcwd(str, 255);
	tmp = str;
	if (str[0] == '/' && str[1] != '\0')
		while (ft_strchr(str, '/'))
			str++;
	while (vlist && ft_strcmp(vlist->vname, "HOME"))
		vlist = vlist->next;
	if (vlist && !ft_strcmp(vlist->vname, "HOME"))
		home = vlist->vcntt;
	ft_putstr("\033[36m");
	ft_putstr("[minishell]=> ");
	ft_putstr("\033[31m");
	ft_putstr((home && !ft_strcmp(home, tmp)) ? "~" : str);
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
		prompt(vlist);
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
