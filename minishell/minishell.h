/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 18:07:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/06 16:08:11 by fcapocci         ###   ########.fr       */
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
void						unset_env(t_env **vlist, char **args);
t_env						*save_link(t_env *list, char *arg);

/*
**	setenv.c
*/

t_env						*creat_link_env(char **args, int rp);
t_env						*insert_cntt(t_env *vlist, char *cntt, int rp);
t_env						*set_env(t_env *vlst, char **args, int rp);

/*
**	cmd.c
*/

int							check_path(char ***args, char **path);
int							get_cmd(char *line, t_env *env_list);
int							cmp_rpl(t_path *tmp, char ****args);
int							cmp_rpl2(char ****args);
t_path						**tab_list(char **path);

/*
**	builtins.c
*/

int							get_builtins(char *line);

/*
**	cd.c
*/

void						new_path(char **path, char *rep);
int							move_ok(t_env *vlist, char *rep);
t_env						*change_pwd(t_env *vlist, char *rep);
void						replace_line(char **line, char *new_line);
t_env						*cd_env(t_env *vlist, char **args);

/*
**	cd2.c
*/

int							get_home_old(t_env *env, char *type);
int							change_directory(char *path, t_env **vlist);
int							error_cd(char *str, char *path, int nb);
int							check_droit(char *path);

/*
**	free.c
*/

int							free_get_cmd(char ***args, char ***path,
							char **line, int nb);
void						quit(t_env **list, char **line);
int							free_tab_list(t_path ***tab_list, int nb);
int							is_builts(char **line, char ***args, int nb);

/*
**	free2.c
*/

void						free_link(t_env **vlist, int in);
void						quit_builts(char **line, char ***args);
int							quit_char(char **ptr, int nb);

/*
**	execute.c
*/

char						**split_env_list(t_env *vlist);
int							execute_cmd(char **args, t_env *list);
int							exe_builtins(char *line, t_env **vlist);

/*
**	print.c
*/

void						not_perms(char *name);
void						no_cmd(char *name);
void						print_env(t_env *vlist);

#endif
