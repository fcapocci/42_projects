/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:02:17 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/26 14:39:12 by fcapocci         ###   ########.fr       */
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

t_data						*creat_elem(int x, int y, char c);
t_data						*creat_list(char **data_tab);
t_data						*pars(char *files);

/*
**	error.c
*/

void						usage_error(int argc);

#endif
