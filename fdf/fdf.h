/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:02:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/27 20:42:08 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft/libft.h"

typedef struct				s_data
{
	int						x;
	int						y;
	int						h;
	struct s_data			*next;
}							t_data;

/*
**	parsing.c
*/

t_data						*creat_elem(int x, int y, int c);
t_data						*creat_list(t_data *d_list, char **data_tab, int y);
t_data						*pars(char *files, int ret);

/*
**	error.c
*/

void						usage_error(int argc);

/*
**	free.c
*/

void						free_list(t_data **d_list);

#endif
