/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:41:57 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/28 17:01:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _42SH_H

# define _42SH_H

#include <sys/stat.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>

# define SIZE_HASH 300
# define SIZE_SORT 27

# define NAME "42sh"
# define HISTORY_NAME "/tmp/42sh_history.txt"

# define ERROR -1
# define BUILT 1
# define EXE 2

typedef struct				s_multi_line
{
	char					*line;					//line ecrite au clavier
	struct s_multi_line		*next;					//line suivante
}							t_multi_line;

typedef struct				s_history_shell
{
	char					*line;					//ligne ecrite au clavier
	struct s_history_shell	*next;					//ligne suivante
	struct s_history_shell	*prev;					//ligne precedente
}							t_history_shell;

typedef struct				s_bin
{
	char					*name;					//name du binaire
	char					*path;					//path du binaire
	char					*path_name;				//path Plus name
	int						i_hash;					//position hash bin
	int						i_sort;					//position sort bin
	unsigned int			len_name;				//long name du binaire
	struct stat				stat_bin;				//status du bin
	struct s_bin			*h_next;				//next hash bin
	struct s_bin			*s_next;				//next sort bin
}							t_bin;

typedef struct				s_env
{
	char					*name;					//name de la varoble d'env
	char					*content;				//contenu de la variable d'env
	unsigned int			i;						//index de la varoable d'env
	struct s_env			*next;					//variable suivante
}							t_env;

typedef struct				s_42sh
{
	char					**path;					//tableaux des paths
	char					*path_line;				//path recu avec env
	char					*term_name;				//nom du terminal dans env
	char					*home;					//path du home
	int						fd_history;				//fichier avec l'hitorique de toules les lignes du shell
	unsigned int			len_home;				//len home
	unsigned int			nb_bin;					//nombre de binaire qui compose le path
	t_bin					*hash_bin[SIZE_HASH];	//table de hash des binaires
	t_bin					*sort_bin[SIZE_SORT];	//tableau des binaires tries par ordre alphabetique
	t_env					*lst_env;				//liste des varoables d'env
	t_history_shell			*history;				//liste de l'hitorique
	t_history_shell			*curs_history;			//position dans la liste chainee
	t_history_shell			*last_add;				//adresse de la derniere ligne ajoutee
	struct termios			reset;					//structure sans modif du term
	struct termios			setting;				//structure avec modif du term
	struct winsize			info_w;					//info si la fenetre du terminal

}							t_42sh;

t_42sh						*get_struct_42sh(t_42sh **sh);
int							save_win_size(void);
void						print_sign(int signal);
char						**save_argv(t_bin *bin, char *line);
int							builtin_error(char *builtin);
t_42sh						*init_sh(char **env);
int							init_term(t_42sh **sh);
t_env						*save_env(char **env);
int							save_hash_bin(t_42sh *sh);
int							save_sort_bin(t_42sh *sh, t_bin **new_);
void						sort_list(t_bin **liste,
		int (fonc_tri)(void *, void *));
int							name_tri(void *node1, void *node2);
int							autocompletion(t_42sh *sh, char *entry);
int							i_table_hash(char *s, unsigned int len_tab);
void						loop_shell(t_42sh *sh);
t_env						*new_env(char *name, char *content, unsigned int i);
int							del_hash_bin(t_42sh *sh);
int							del_sh(t_42sh **sh);
int							del_one_env(t_env **lst, char *name);
t_env						*del_env(t_env **lst);
int							check_builtin(t_42sh **sh, t_multi_line **line);
int							check_bin(t_42sh *sh, t_multi_line **m_line);
int							builtin_echo(t_42sh **sh, t_multi_line **m_line);
int							builtin_setenv(t_42sh **sh, t_multi_line **m_line);
void						error(char *s);
void						print_env(t_42sh *sh);
t_multi_line				*get_multi_line(void);
void						del_multi_line(t_multi_line **m_line);
char						**new_var_env(t_42sh *sh);
void						print_status(void);

t_history_shell				*add_new_line_head(char **line, t_history_shell **lst);
int							save_history(t_42sh *sh);
int							save_m_line(t_42sh *sh, t_multi_line **m_line);
void						del_history(void);
void						print_history(void);
int							print_promt(t_42sh *sh);

# endif
