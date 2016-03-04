/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:38:25 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/04 12:14:34 by fcapocci         ###   ########.fr       */
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
	long long		nanotime;
	struct s_arg	*prev;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_dir
{
	char			type;
	char			*modes;
	char			acl;
	long			nblink;
	char			*owner;
	char			*grp;
	long			tall;
	int				minor;
	int				major;
	char			*date;
	long long		numdate;
	long long		nano_numdate;
	long			blksize;
	char			*name;
	struct s_dir	*prev;
	struct s_dir	*next;
}					t_dir;

int					manage(int argc, char **argv, t_opt *optl);
int					manage_read(int argc, char **argv, t_opt *optl);
int					sub_manage(int argc, t_opt *op, t_arg *arg, t_dir *flist);
char				*manage_rep(int argc, char **argv);
int					read_dir(t_opt *optl, t_dir **list, char *dirname);
int					read_file(t_opt *op, t_dir **flist, t_dir **first, char *d);
void				recursion(t_opt *optl, t_dir *start, t_dir *end);
t_dir				*last_link(t_dir *list);

char				*dating(const time_t *clock);
char				*hide_path(char *entity);
long				total_blk(t_dir *list);

t_dir				*get_content(t_opt *op, char *name);
char				*take_modes(mode_t st_mode);
char				take_type(mode_t st_mode);
char				take_acl_el(char *entity);

t_arg				*read_arg(t_opt *optl, int argc, char **argv);
t_arg				*get_arg_content(char *entity);
t_arg				*swap_arg_content(t_arg *list1, t_arg *link2);
t_arg				*sort_arg_time(t_opt *optl, t_arg *argument);
t_arg				*sort_arg_nanotime(t_opt *optl, t_arg *argument);
char				**sort_arg_lex(t_opt *optl, int argc, char **argv);
void				sort_list(t_opt *op, t_dir ***lst, t_dir **slst, char *ent);
void				get_minor_major(int *minor, int *major, dev_t st_rdev);

void				padd_nblink(t_dir *list, t_dir *start);
void				padd_owner(t_dir *list, t_dir *start);
void				padd_grp(t_dir *list, t_dir *start);
void				padd_tall(t_dir *list, t_dir *start);
void				padd_min_maj(t_dir *list, t_dir *start, int i);

void				print_tall(t_dir *start, t_dir *list);
void				print_opt_l(t_opt *optl, t_dir *start, t_dir *list);
void				printing(t_opt *optl, t_dir *start, t_dir *end);
void				print_file(t_opt *optl, t_dir *start);
void				illegal_option(char c);
int					permis_denied(char *entity);
void				print_error(char *entity, int fonction);
void				print_path(char *dirname, int save, t_dir *flist);
void				get_link(char *file);
void				colors(t_opt *optl, char *name, char type, char *modes);
void				print_colors(char *s1, char *s2, char *s3);

t_opt				*creat_elem(t_opt *optl, char o);
int					take_option(t_opt **optl, int *argc, char ***argv);
int					check_option(char o);
int					op_ok(t_opt *optl, char o);

t_arg				*manage_sort_arg(t_opt *optl, t_arg *arg);
t_dir				*manage_sort(t_opt *optl, t_dir *list);

t_dir				*ft_merge_sort(t_dir *list);
t_dir				*ft_merge(t_dir *lista, t_dir *listb);
void				ft_split(t_dir **list, int size);
void				ft_splitlist(t_dir *list, t_dir **a, t_dir **b, int i);

t_dir				*ft_merge_sort_time(t_dir *list);
t_dir				*ft_merge_time(t_dir *lista, t_dir *listb);
void				ft_split_time(t_dir **list, int size);
void				ft_splitlist_time(t_dir *list, t_dir **a, t_dir **b, int i);

t_dir				*ft_merge_sort_ntime(t_dir *list);
t_dir				*ft_merge_ntime(t_dir *lista, t_dir *listb);
void				ft_split_ntime(t_dir **list, int size);
void				ft_splitlist_ntime(t_dir *l, t_dir **a, t_dir **b, int i);

void				free_list(t_dir **list);

#endif
