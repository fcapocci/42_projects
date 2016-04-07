/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcapocci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:30:30 by fcapocci          #+#    #+#             */
/*   Updated: 2016/04/07 16:46:20 by fcapocci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char			*g_tab_error[31] =
{"terminal line hangup", "interrupt program", "quit program",
	"illegal instruction", "trace trap", "abort program",
	"emulate instruction executed", "floating-point exception", "kill program",
	"bus error", "segmentation violation", "non-existent system call invoked",
	"write on a pipe with no reader", "real-time timer expired",
	"software termination signal", "urgent condition present on socket", "stop",
	"stop signal generated from keyboard", "continue after stop",
	"child status has changed",
	"background read attempted from control terminal",
	"background write attempted to control terminal",
	"I/O is possible on a descriptor", "cpu time limit exceeded",
	"file size limit exceeded", "virtual time alarm", "profiling timer alarm",
	"Window size change", "status request from keyboard",
	"User defined signal 1", "User defined signal 2"};

void		print_sign(int signal)
{
	if (signal == SIGTSTP || signal == SIGINT)
		ft_putstr(g_tab_error[signal]);
}

void		print_status(void)
{
	int				i;

	i = 1;
	while (i < 32)
		signal(i++, print_sign);
}
