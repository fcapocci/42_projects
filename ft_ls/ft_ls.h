/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:38:25 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/27 20:23:16 by fcapocci         ###   ########.fr       */
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

typedef struct			s_opt
{
	char			o;
	struct s_opt	*next;
}						t_opt;

typedef struct			s_dir
{
	char			type;
	char			*modes;
	long			nblink;
	char			*owner;
	char			*grp;
	long			tall;
	char			*date;
	char			*name;
	struct s_dir	*next;
}						t_dir;

t_dir					*add_link(t_dir *list, struct stat stats, char *name);
t_dir					*add_content(t_dir *list, struct stat stats, char *name);
char					*dating(const time_t *clock);
char					*take_modes(mode_t st_mode);
char					take_type(mode_t st_mode);
void					printing(t_dir *list);

#endif
