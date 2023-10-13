/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:16:34 by paescano          #+#    #+#             */
/*   Updated: 2023/10/13 11:28:02 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_select_exec(int i)
{
	if (g_global.cmd[i].cmds[0] != NULL)
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
		else
			g_global.exit_status = ft_exec();
	}
}

void	single_command()
{
	
}