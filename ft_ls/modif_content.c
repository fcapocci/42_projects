/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:13:40 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/10 11:19:09 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*dating(const time_t *clock)
{
	char	*crt_date;
	char	*date;

	date = ctime(clock);
	crt_date = ft_strsub(date, 4, 12);
	return (crt_date);
}

char		*hide_path(char *entity)
{
	char	*new;
	int		len;

	while (ft_strchr(entity, '/'))
		entity++;
	len = ft_strlen(entity);
	new = ft_strsub(entity, 0, len);
	return (new);
}

long		total_blk(t_dir *list)
{
	long	total;

	total = 0;
	while (list)
	{
		total += list->blksize;
		list = list->next;
	}
	return (total);
}
