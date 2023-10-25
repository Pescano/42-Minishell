/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:04:23 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/25 16:43:26 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exe_one(void)
{
	pid_t		pid;
	int			wi;
	char		**env;

	pid = fork();
	if (pid == -1)
		ft_free_error(ERROR_FORK);
	else if (!pid)
	{
		g_global.cmd[0].cmds = ft_com_path(g_global.cmd[0].cmds);
		env = ft_format_env();
		execve(g_global.cmd[0].cmds[0], g_global.cmd[0].cmds, env);
		ft_print_error(ERROR_ECVE, g_global.cmd[0].cmds[0]);
		ft_freevpp((void **)env);
		ft_finish(127);
	}
	else
	{
		wait(&wi);
		g_global.exit_status = WEXITSTATUS(wi);
	}
}

void	ft_exe_more(int i)
{
	char	**env;

	g_global.cmd[i].cmds = ft_com_path(g_global.cmd[i].cmds);
	env = ft_format_env();
	execve(g_global.cmd[i].cmds[0], g_global.cmd[i].cmds, env);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_print_error(ERROR_ECVE, g_global.cmd[i].cmds[0]);
	ft_freevpp((void **)env);
	ft_finish(127);
}

static void	set_pipes(int i)
{
	if (ft_set_fds(i))
	{
		g_global.exit_status = 1;
		return ;
	}
	if (i < g_global.n_cmds - 1)
	{
		if (g_global.t_stdout < 0)
			dup2(g_global.pipes.p1[1], STDOUT_FILENO);
		ft_closep(g_global.pipes.p1, 1);
	}
	if (i > 0)
	{
		if (g_global.t_stdin < 0)
			dup2(g_global.pipes.p2[0], STDIN_FILENO);
		ft_closep(g_global.pipes.p2, 0);
	}
}

void	ft_select_exec(int i)
{
	if (g_global.n_cmds > 1)
		set_pipes(i);
	if (g_global.cmd[i].cmds && g_global.cmd[i].cmds[0] != NULL)
	{
		if (ft_strcmp(g_global.cmd[i].cmds[0], "echo") == 0)
			g_global.exit_status = ft_echo(g_global.cmd[i].cmds + 1);
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "cd") == 0)
			g_global.exit_status = ft_cd(g_global.cmd[i].cmds[1]);
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "pwd") == 0)
			g_global.exit_status = ft_pwd();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "export") == 0)
			g_global.exit_status = ft_export(g_global.cmd[i].cmds + 1);
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "unset") == 0)
			g_global.exit_status = ft_unset(g_global.cmd[i].cmds + 1);
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "env") == 0)
			g_global.exit_status = ft_env(g_global.cmd[i].cmds[1]);
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "exit") == 0)
			g_global.exit_status = ft_exit(g_global.cmd[i].cmds + 1);
		else if (g_global.n_cmds == 1)
			ft_exe_one();
		else
			ft_exe_more(i);
	}
	if (g_global.n_cmds > 1)
		ft_finish(g_global.exit_status);
}
