/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/02 17:32:01 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv)
{
	pid_t		father;
	int			i;

	father = fork();
	i = father;
	if (argc > 1)
	{
		if (father > 0)
		{
			ft_putendl("processus pere");
			wait(&i);
		}
		if (father == 0)
		{
			sleep(5);
			execve("/bin/ls", argv, NULL);
		}
	}
	return (0);
}
