/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exec_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:16:44 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 11:17:17 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_single_command(void)
{
	if (ft_set_fds(0))
	{
		g_global.exit_status = 1;
		return ;
	}
	ft_select_exec(0);
	ft_reset_fds();
}

static void	first_command(void)
{
	pid_t	pid;
	int		wi;

	if (pipe(g_global.pipes.p1))
		ft_free_error(ERROR_PIPE);
	pid = fork();
	if (pid < 0)
	{
		ft_closep(g_global.pipes.p1, 2);
		ft_free_error(ERROR_FORK);
	}
	else if (!pid)
	{
		ft_closep(g_global.pipes.p1, 0);
		ft_select_exec(0);
	}
	else
	{
		wait(&wi);
		g_global.exit_status = WEXITSTATUS(wi);
	}
	ft_closep(g_global.pipes.p1, 1);
	g_global.pipes.p2[0] = g_global.pipes.p1[0];
}

static void	middle_command(int i)
{
	pid_t	pid;
	int		wi;

	if (pipe(g_global.pipes.p1))
		ft_free_error(ERROR_PIPE);
	pid = fork();
	if (pid < 0)
	{
		ft_closep(g_global.pipes.p1, 2);
		ft_closep(g_global.pipes.p2, 0);
		ft_free_error(ERROR_FORK);
	}
	else if (!pid)
	{
		ft_closep(g_global.pipes.p1, 0);
		ft_select_exec(i);
	}
	else
	{
		wait(&wi);
		g_global.exit_status = WEXITSTATUS(wi);
	}
	ft_closep(g_global.pipes.p2, 0);
	g_global.pipes.p2[0] = g_global.pipes.p1[0];
	ft_closep(g_global.pipes.p1, 1);
}

void	ft_multiple_cmds(void)
{
	pid_t	pid;
	int		wi;
	int		i;

	first_command();
	i = 1;
	while (i < g_global.n_cmds - 1)
		middle_command(i++);
	pid = fork();
	if (pid < 0)
		ft_free_error(ERROR_FORK);
	else if (!pid)
		ft_select_exec(g_global.n_cmds - 1);
	else
	{
		wait(&wi);
		g_global.exit_status = WEXITSTATUS(wi);
	}
}
