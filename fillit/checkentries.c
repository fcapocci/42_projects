/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkentries.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:32:25 by vcastro-          #+#    #+#             */
/*   Updated: 2016/01/08 18:42:31 by vcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_file_empty(char *file)
{
	if (!file)
		return (ERROR);
	return (SUCCESS);
}

int		are_chars_ok(char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\0')
	{
		if (file[i] != '.' && file[i] != '#' && file[i] != '\n')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int		is_file_len_ok(char *file)
{
	if (ft_strlen(file) > 545)
		return (ERROR);
	return (SUCCESS);
}

int		is_sequence_ok(char *file)
{
	int		linecount;
	char	lastchar;

	linecount = 0;
	while (*file != '\0')
	{
		if (lastchar && lastchar != '\n' && *file == '\n')
			linecount++;
		else if (lastchar && lastchar == '\n' && (*file == '\n' ||
				*file == '\0') && linecount == 4)
			linecount = 0;
		if (linecount > 4)
			return (ERROR);
		lastchar = *file;
		file++;
	}
	if (linecount < 4)
		return (ERROR);
	return (SUCCESS);
}

int		is_format_ok(char *file)
{
	int		charcount;
	char	lastchar;

	charcount = 0;
	if (file[0] == '\n')
		return (ERROR);
	while (*file != '\0')
	{
		if (*file != '\n')
			charcount++;
		else
		{
			if ((lastchar && lastchar == '\n' && file[1] == '\n') ||
				(charcount != 4 && charcount != 0) ||
				(lastchar && lastchar == '\n' && file[1] == '\0'))
				return (ERROR);
			charcount = 0;
		}
		lastchar = *file;
		file++;
	}
	if (charcount != 0 && lastchar && lastchar != '\n')
		return (ERROR);
	return (SUCCESS);
}
