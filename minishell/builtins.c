/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 22:07:05 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/12 23:19:21 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				get_builtins(char *line)
{
	char		**args;

	line = sup_tab(line);
	args = ft_strsplit(line, ' ');
	if (!ft_strcmp(args[0], "cd"))
		return (is_builts(&line, &args, 1));
	if (!ft_strcmp(args[0], "setenv"))
		return (is_builts(&line, &args, 1));
	if (!ft_strcmp(args[0], "unsetenv"))
		return (is_builts(&line, &args, 1));
	if (!ft_strcmp(args[0], "env"))
		return (is_builts(&line, &args, 1));
	if (!ft_strcmp(args[0], "exit"))
		return (is_builts(&line, &args, -1));
	return (is_builts(&line, &args, 0));
}
