/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 21:24:06 by fcapocci          #+#    #+#             */
/*   Updated: 2016/12/09 00:20:15 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

static void				print_pid(char *str)
{
	pid_t				pid;
	pid_t				ppid;

	pid = getpid();
	ppid = getppid();
	ft_putstr_fd("curent pid in ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" == ", 2);
	ft_putnbr_fd(pid, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("parent pid in ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" == ", 2);
	ft_putnbr_fd(ppid, 2);
	ft_putchar_fd('\n', 2);
}

static void				ft_exit(char **line, t_cmd *cmd)
{
	if (*line != NULL)
		ft_memdel((void**)line);
	if (cmd != NULL)
		free_cmd(cmd);
	exit(EXIT_FAILURE);
}

static int				prompt(void)
{
	ft_putstr("\033[0;36m");
	ft_putstr("pouetshell$> ");
	ft_putstr("\033[0;m");
	return (1);
}

static int				check_access(t_cmd *cmd, int *ret)
{
	if (!cmd->arg || (access(cmd->arg[0], X_OK) == -1))
	{
		*ret = 1;
		ft_putstr_fd(cmd->arg[0], 2);
		ft_putendl_fd(": cmd not found", 2);
		return (-1);
	}
	return (0);
}

static void				ft_execve(t_cmd *cmd)
{
	extern char			**environ;

	ft_putendl_fd("\nFT_EXECVE", 2);
	print_pid("ft_execve");
	if (cmd->pipefd[0] != -1)
	{
		close(cmd->pipefd[1]);
		dup2(cmd->pipefd[0], STDIN_FILENO);
	}
	else if (cmd->op == PIP)
	{
		close(cmd->right->pipefd[0]);
		dup2(cmd->right->pipefd[1], STDOUT_FILENO);
	}
	if (check_access(cmd, &cmd->done) == -1
			|| execve(cmd->arg[0], cmd->arg, environ) == -1)
	{
		ft_putendl_fd("EXIT FT_FATHER", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

static void				ft_pipe(t_cmd **cmd)
{
	pid_t				pid;
	int					ret;

	ft_putendl_fd("\nFT_PIPE", 2);
	ret = 1;
	print_pid("ft_pipe");
	if ((pid = fork()) != -1)
	{
		if (pid == 0)
			ft_execve(*cmd);
		else
			waitpid(pid, &ret, WUNTRACED);
	}
	if (WIFEXITED(ret))
		ret = WEXITSTATUS(ret);
	(*cmd)->done = ret;
	printf("cmd->done in ft_pipe== %d\n", (*cmd)->done);
	*cmd = (*cmd)->right;
}

int				ft_exe(t_cmd *cmd)
{
	pid_t				pid;

	ft_putendl_fd("\nFT_EXE", 2);
	print_pid("ft_exe");
	if ((pid = fork()) != -1)
	{
		if (pid == 0)
		{
			while (cmd->op == PIP)
			{
				pipe(cmd->right->pipefd);
				ft_pipe(&cmd);
				ft_putstr("L\n");
				printf("cmd->done == %d\n", cmd->done);
			}
			if (cmd->op != PIP && cmd->done == -1)
				ft_execve(cmd);
		}
		else
			waitpid(pid, 0, WUNTRACED);
	}
	return (0);
}

static void				loop_cmd(t_cmd *cmd)
{
	int					save_done;

	while (cmd && cmd->arg && cmd->arg[0])
	{
		ft_putendl_fd("PASS", 2);
		ft_exe(cmd);
		save_done = cmd->done;
		while ((cmd->right && cmd->right->done >= 0)
				|| (cmd->right && cmd->op == ET && save_done != 0)
				|| (cmd->right && cmd->op == OU && save_done == 0))
			cmd = cmd->right;
		printf("cmd == %s\n", cmd->arg[0]); //debug
		cmd = cmd->right;
	}
}

int						main(void)
{
	char				*line;
	t_cmd				*cmd;

	line = NULL;
	while (prompt())
	{
	//	line = get_line();
		get_next_line(0, &line);
		if (ft_strstr(line, "exit"))
			ft_exit(&line, NULL);
		if ((cmd = parse_cmd(line, NULL, 0)) != NULL)
			loop_cmd(cmd);
		ft_memdel((void**)&line);
		free_cmd(cmd);
	}
	return (0);
}
