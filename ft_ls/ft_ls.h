/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:38:25 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/25 19:35:42 by fcapocci         ###   ########.fr       */
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

typedef struct			s_dir
{
	char	type;
	char	*modes;
	long	nblink;
	char	*owner;
	char	*grp;
	long	tall;
	char	*date;
	char	*name;
	s_dir	*next;
}						t_dir;

t_dir					*add_link(t_dir *list, struct stats);
t_dir					*add_content(t_dir *list, struct stats);
char					*dating(const time_t *clock);
char					*take_modes(mode_t st_mode);
char					take_type(mode_t st_mode);

#endif
