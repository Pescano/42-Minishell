/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:04:43 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 11:05:01 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_init_cmd(void)
{
	t_cmd	*tmp;
	int		i;

	tmp = (t_cmd *)malloc(sizeof(t_cmd) * g_global.n_cmds);
	if (!tmp)
		ft_free_error(ERROR_MALLOC);
	i = 0;
	while (i < g_global.n_cmds)
	{
		tmp[i].in = -1;
		tmp[i].out = -1;
		tmp[i].cmds = NULL;
		tmp[i].fd_in = NULL;
		tmp[i].fd_in2 = NULL;
		tmp[i].fd_out = NULL;
		tmp[i].fd_out2 = NULL;
		i++;
	}
	g_global.cmd = tmp;
}

void	ft_free_cmd(void)
{
	int	i;

	i = 0;
	while (i < g_global.n_cmds)
	{
		if (g_global.cmd[i].cmds)
			ft_freevpp((void **)g_global.cmd[i].cmds);
		if (g_global.cmd[i].fd_in)
			ft_freevpp((void **)g_global.cmd[i].fd_in);
		if (g_global.cmd[i].fd_in2)
			ft_freevpp((void **)g_global.cmd[i].fd_in2);
		if (g_global.cmd[i].fd_out)
			ft_freevpp((void **)g_global.cmd[i].fd_out);
		if (g_global.cmd[i].fd_out2)
			ft_freevpp((void **)g_global.cmd[i].fd_out2);
		i++;
	}
	free(g_global.cmd);
}

void	ft_add_redir_cmd(char *redir, char *arg, int i)
{
	if (redir[0] == '<' && redir[1] == '<')
	{
		g_global.cmd[i].fd_in2 = ft_add_pp(arg, g_global.cmd[i].fd_in2);
		g_global.cmd[i].in = 1;
	}
	else if (redir[0] == '<')
	{
		g_global.cmd[i].fd_in = ft_add_pp(arg, g_global.cmd[i].fd_in);
		g_global.cmd[i].in = 0;
	}
	else if (redir[0] == '>' && redir[1] == '>')
	{
		g_global.cmd[i].fd_out2 = ft_add_pp(arg, g_global.cmd[i].fd_out2);
		g_global.cmd[i].out = 1;
	}
	else if (redir[0] == '>')
	{
		g_global.cmd[i].fd_out = ft_add_pp(arg, g_global.cmd[i].fd_out);
		g_global.cmd[i].out = 0;
	}
}
