/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:38:25 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/04 19:00:04 by fcapocci         ###   ########.fr       */
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
	char			*name;
	struct s_dir	*next;
}					t_dir;

char				*manage_rep(char **argv);
int					read_dir(t_dir **list, char *dirname);

char				*dating(const time_t *clock);
char				*hide_path(char *entity);

t_dir				*get_content(char *name);
char				*take_modes(mode_t st_mode);
char				take_type(mode_t st_mode);

void				padd_nblink(t_dir *list, t_dir *start);
void				padd_owner(t_dir *list, t_dir *start);
void				padd_grp(t_dir *list, t_dir *start);
void				padd_tall(t_dir *list, t_dir *start);

void				printing(t_opt *optl, t_dir *list);
void				illegal_option(char c);

t_opt				*creat_elem(t_opt *optl, char o);
int					take_option(t_opt **optl, int argc, char **argv);
int					check_option(char o);
int					option_ok(t_opt *optl, char o);

#endif
