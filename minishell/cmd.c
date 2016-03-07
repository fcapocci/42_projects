/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 04:19:53 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/07 22:45:17 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				get_cmd(char *line, char **env)
{
	t_env		*vlist;
	t_env		*start;
	char		*cmd;

	if (!(vlist = creat_list(env)))
		return (-1);
	start = vlist;
	while (ft_strcmp(vlist->vname, "PATH") != 0)
		vlist = vlist->next;
	cmd = ft_strjoin(vlist->vcntt, line);
	if (!ft_strcmp(cmd, vlist->vcntt))
		execute_cmd(cmd, env);
	ft_memdel((void**)&cmd);
	free_vlist(start);
	return (0);
}
