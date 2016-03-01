/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <fcapocci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 16:49:50 by fcapocci          #+#    #+#             */
/*   Updated: 2016/03/01 22:36:59 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	pid_t		father;

	father = fork();
	if (argc > 1)
	{
		if (father > 0)
		{
			printf("processus pere");
			wait(&father);
		}
		if (father == 0)
		{
			sleep(5);
			execve("/bin/ls", argv, NULL);
		}
	}
	return (0);
}
