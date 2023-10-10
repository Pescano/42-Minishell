/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:16:34 by paescano          #+#    #+#             */
/*   Updated: 2023/10/10 18:32:37 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_select_exec(int i)
{
	if (g_global.cmd[i].cmds[0] != NULL)
	{
		if (ft_strcmp(g_global.cmd[i].cmds[0], "echo") == 0)
			ft_echo();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "cd") == 0)
			ft_cd();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "pwd") == 0)
			ft_pwd();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "export") == 0)
			ft_export();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "unset") == 0)
			ft_unset();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "env") == 0)
			ft_env();
		else if (ft_strcmp(g_global.cmd[i].cmds[0], "exit") == 0)
			ft_exit();
		else
			ft_exec();
	}
}
// para mañana ir pensando haciendo el selector correctamente para que funcionen
// builtins y ejecutables
