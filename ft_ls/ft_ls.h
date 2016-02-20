/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:38:25 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/20 13:37:33 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct		s_opt
{
	char			c;
	struct s_opt	*next;
}					t_opt;

typedef struct		s_arg
{
	char			*argument;
	char			type;
	long long		time;
	struct s_arg	*prev;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_dir
{
	char			type;
	char			*modes;
	long			nblink;
	char			*owner;
	char			*grp;
	long			tall;
	char			*date;
	long long		numdate;
	long			blksize;
	char			*name;
	struct s_dir	*prev;
	struct s_dir	*next;
}					t_dir;

int					manage(int argc, char **argv, t_opt *optl, t_dir *list);
int					manage_read(int argc, char **argv, t_opt *optl, t_dir *lst);
char				*manage_rep(int argc, char **argv);
int					read_dir(t_opt *optl, t_dir **list, char *dirname);
int					read_file(t_dir **flist, t_dir **first, char *dirname);

char				*dating(const time_t *clock);
char				*hide_path(char *entity);
long				total_blk(t_dir *list);

t_dir				*get_content(char *name);
char				*take_modes(mode_t st_mode);
char				take_type(mode_t st_mode);

t_arg				*read_arg(t_opt *optl, int argc, char **argv);
t_arg				*get_arg_content(char *entity);
t_arg				*swap_arg_content(t_arg *list1, t_arg *link2);
t_arg				*sort_arg_time(t_arg *argument);
char				**sort_arg_lex(int argc, char **argv);
void				sort_list(t_dir ***lst, t_dir **slst, char *ent);
t_dir				*swap_dir_content(t_dir *link1, t_dir *link2);
t_dir				*sort_dir_lex(t_dir *list);
t_dir				*sort_dir_time(t_dir *list);

void				padd_nblink(t_dir *list, t_dir *start);
void				padd_owner(t_dir *list, t_dir *start);
void				padd_grp(t_dir *list, t_dir *start);
void				padd_tall(t_dir *list, t_dir *start);

void				print_opt_l(t_dir *start, t_dir *list);
void				printing(t_opt *optl, t_dir *start, t_dir *end);
void				print_file(t_opt *optl, t_dir *start);
void				illegal_option(char c);
int					permis_denied(char *entity);
void				print_error(char *entity, int fonction);
void				print_path(char *dirname, int save, t_dir *flist);
void				get_link(char *file);

t_opt				*creat_elem(t_opt *optl, char o);
int					take_option(t_opt **optl, int *argc, char ***argv);
int					check_option(char o);
int					option_ok(t_opt *optl, char o);

#endif
