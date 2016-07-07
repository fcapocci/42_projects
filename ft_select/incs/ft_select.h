/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:36:07 by fcapocci          #+#    #+#             */
/*   Updated: 2016/07/07 08:45:07 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"

# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <stdlib.h>

# define ERR -1
# define OK 0

typedef struct			s_lst
{
	char				*name;
	size_t				len_name;
	int					type;
	int					selected;
	size_t				num;
	struct s_lst		*prev;
	struct s_lst		*next;
}						t_lst;

//typedef struct		s_term
//{
//}						t_term;

int						ft_select(int argc, char **argv);
t_lst					*init_lst(int argc, char **argv);
void					print_argv(t_lst *lst);
void					free_lst(t_lst *lst);

# endif
