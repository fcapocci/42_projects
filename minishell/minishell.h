/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 18:07:32 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/23 00:37:39 by fcapocci         ###   ########.fr       */
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
char						*srch_tld(char *line, char *vcntt);
char						**scan_tld(char **args, t_env *vlist);
void						unset_env(t_env **vlist, char **args);
char						**rp_shlvl(char **env);

/*
**	setenv.c
*/

t_env						*creat_link_env(char **args, int rp);
t_env						*insert_cntt(t_env *vlist, char *cntt, int rp);
t_env						*set_env(t_env *vlst, char **args, int rp);

/*
**	cmd.c
*/

int							check_line(char **args);
int							check_path(char ***args, char **path);
int							get_cmd(char *line, t_env *env_list);
int							cmp_rpl(t_path *tmp, char ****args);
t_path						**tab_list(char **path);

/*
**	builtins.c
*/

int							get_builtins(char *line);

/*
**	cd.c
*/

int							get_home_old(t_env *env, char *type);
int							change_directory(char *path, t_env **vlist);
int							check_droit(char *path);
t_env						*cd_env(t_env *vlist, char **args);

/*
**	free.c
*/

int							free_get_cmd(char ***args, char ***path,
							char **line, int nb);
void						quit(t_env **list, char **line);
void						free_plist(t_path **plist);
int							free_tab_list(t_path ***tab_list, int nb);
int							is_builts(char **line, char ***args, int nb);

/*
**	free2.c
*/

void						free_link(t_env **vlist, int in);
void						quit_builts(char **line, char ***args);
int							quit_char(char **ptr, int nb);
int							quit_dubblechar(char **ptr, char **str, int nb);

/*
**	execute.c
*/

char						**split_env_list(t_env *vlist);
int							execute_cmd(char **args, t_env *list);
int							exe_builtins(char *line, t_env **vlist);

/*
**	print.c
*/

void						error_cmd(int nb, char *cmd);
void						not_perms(char *name);
void						no_cmd(char *name);
void						print_env(t_env *vlist);
int							error_cd(char *str, char *path, int nb);

#endif
