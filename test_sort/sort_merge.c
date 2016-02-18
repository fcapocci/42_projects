/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_merge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:41:31 by fcapocci          #+#    #+#             */
/*   Updated: 2016/02/18 23:18:55 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_list
{
	char			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list		*sort_arg(t_list *list)
{
	t_list	*start;

	start = list[1];
	
	return (list[1]);
}

t_list		*get_arg(char *entity)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->content = entity;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

int			main(int argc, char **argv)
{
	int		i;
	t_list	*list[2];

	list[0] = NULL;
	i = 1;
	while (i != argc)
	{
		if (!list[0])
		{
			list[0] = get_arg(argv[i]);
			list[1] = list[0];
		}
		else
		{
			list[0]->next = get_arg(argv[i]);
			list[0]->next->prev = list[0];
			list[0] = list[0]->next;
		}
		i++;
	}
	while (list[1])
	{
		printf("%s\n", list[1]->content);
		list[1] = list[1]->next;
	}
	printf("--------------------------------\n");
	while (list[1])
		list[1] = list[1]->prev;
	list[1] = sort_arg(list[1]);
	return (0);
}
