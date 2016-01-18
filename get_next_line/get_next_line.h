/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:21:09 by fcapocci          #+#    #+#             */
/*   Updated: 2016/01/18 17:42:40 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1

int				get_next_line(int const fd, char **line);

typedef struct	s_files
{
	char		*buff;
	int			save;
}				t_files;

#endif
