/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/02 15:02:42 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	pid_t		father;

	father = fork();
	if (argc > 1)
	{
		if (father > 0)
		{
			wait(&father);
			printf("processus pere");
		}
		if (father == 0)
		{
			sleep(5);
			execve("/bin/ls", argv, NULL);
		}
	}
	return (0);
}
