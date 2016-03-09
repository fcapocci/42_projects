/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 18:07:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/09 16:14:34 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/wait.h>

typedef struct				s_env
{
	char					*vname;
	char					*vcntt;
	struct s_env			*next;
}							t_env;

/*
**	list.c
*/

t_env						*creat_list(char **env);
t_env						*new_link(char *env);

/*
**	cmd.c
*/

int							check_path(char ***args, char **path);
char						*sup_tab(char *line);
int							get_cmd(char *line, t_env *env_list);

/*
**	free.c
*/

int							free_get_cmd(char ***arg, char ***pat, char **line);
void						quit(t_env **list, char **line);

/*
**	execute.c
*/

char						**split_env_list(t_env *vlist);
int							execute_cmd(char **args, t_env *list);

#endif
