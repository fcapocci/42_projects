/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 18:07:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/12 03:51:58 by fcapocci         ###   ########.fr       */
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

typedef struct				s_path
{
	char					*ppath;
	char					*pname;
	struct s_path			*next;
}							t_path;

/*
**	list.c
*/

t_env						*creat_list(char **env);
t_env						*new_link(char *env);
t_path						*creat_plist(char *path);
t_path						*new_plink(char *path, char *d_name);

/*
**	modif_content.c
*/

char						*sup_tab(char *line);

/*
**	cmd.c
*/

int							check_path(char ***args, char **path);
int							get_cmd(char *line, t_env *env_list);
t_path						**tab_list(char **path);

/*
**	free.c
*/

int							free_get_cmd(char ***args, char ***path,
							char **line, int nb);
void						quit(t_env **list, char **line);
int							free_tab_list(t_path ***tab_list, int nb);

/*
**	execute.c
*/

char						**split_env_list(t_env *vlist);
int							execute_cmd(char **args, t_env *list);

/*
**	error.c
*/

void						no_cmd(char *name);

#endif
