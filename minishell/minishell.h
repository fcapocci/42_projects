/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 18:07:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/13 20:47:28 by fcapocci         ###   ########.fr       */
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
t_env						*set_env(t_env *vlst, char *nam, char *cnt, int rp);
t_env						*unset_env(t_env *vlist, char *name);
t_env						*cd_env(t_env *vlist, char *name);
t_env						*insert_cntt(t_env *vlist, char *cntt, int rp);

/*
**	cmd.c
*/

int							check_path(char ***args, char **path);
int							get_cmd(char *line, t_env *env_list);
t_path						**tab_list(char **path);

/*
**	builtins.c
*/

int							get_builtins(char *line);

/*
**	free.c
*/

int							free_get_cmd(char ***args, char ***path,
							char **line, int nb);
void						quit(t_env **list, char **line);
int							free_tab_list(t_path ***tab_list, int nb);
int							is_builts(char **line, char ***args, int nb);
int							quit_builts(char **line, char ***args);

/*
**	execute.c
*/

char						**split_env_list(t_env *vlist);
int							execute_cmd(char **args, t_env *list);
int							exe_builtins(char *line, t_env **vlist);

/*
**	print.c
*/

void						no_cmd(char *name);
void						print_env(t_env *vlist);

#endif
