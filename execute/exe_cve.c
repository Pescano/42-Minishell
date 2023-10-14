/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:04:23 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/14 13:42:18 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exe_one(void)
{
	int		pid;
	int		wi;
	char	**env;

	pid = fork();
	if (pid == -1)
		ft_free_error(ERROR_FORK);
	else if (!pid)
	{
		g_global.cmd[0].cmds = ft_com_path(g_global.cmd[0].cmds);
		env = ft_format_env();
		execve(g_global.cmd[0].cmds[0], g_global.cmd[0].cmds, env);
		ft_freevpp((void **)env);
		ft_finish(-1);
	}
	else
	{
		wait(&wi);
		g_global.exit_status = WEXITSTATUS(wi);
	}
}
