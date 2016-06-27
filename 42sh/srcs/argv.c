/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 21:19:07 by fpasquer          #+#    #+#             */
/*   Updated: 2016/06/23 09:42:50 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/_42sh.h"
#include "../libft/libft.h"


#include <stdio.h>

char						**save_argv(t_bin *bin, char *line)
{
	char					**argv;
	char					**mem;
	unsigned int			nb_word;

	if (line == NULL || bin == NULL)
		return (NULL);
	if ((mem = ft_strsplit_guil(line, ' ')) == NULL)
		return (NULL);
	nb_word = len_y(mem);
	if ((argv = ft_memalloc(sizeof(char *) * (nb_word + 2))) == NULL)
		return (NULL);
	nb_word = 0;
	if ((argv[nb_word++] = ft_strdup(bin->path_name)) == NULL)
		return (NULL);
	while (mem[nb_word] != NULL)
	{
		if ((argv[nb_word] = mem[nb_word]) == NULL)
			return (NULL);
		nb_word++;
	}
	ft_memdel((void**)&mem[0]);
	ft_memdel((void**)&mem);
	return (argv);
}
