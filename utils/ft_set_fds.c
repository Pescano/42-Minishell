/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:17:14 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/30 11:16:57 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_infile(int n)
{
	int	i;
	int	fd;

	if (ft_pplen(g_global.cmd[n].fd_in2))
		fd = ft_heredoc(g_global.cmd[n].fd_in2);
	i = 0;
	while (g_global.cmd[n].fd_in && g_global.cmd[n].fd_in[i])
	{
		if (access(g_global.cmd[n].fd_in[i], R_OK))
		{
			ft_print_error(ERROR_FILE, g_global.cmd[n].fd_in[i]);
			if (ft_pplen(g_global.cmd[n].fd_in2))
				close(fd);
			return (-1);
		}
		i++;
	}
	if (g_global.cmd[n].in == 1)
		return (fd);
	if (ft_pplen(g_global.cmd[n].fd_in2))
		close(fd);
	return (open(g_global.cmd[n].fd_in[i - 1], O_RDONLY));
}

static int	ft_outfile(int n)
{
	int	i;

	i = 0;
	while (g_global.cmd[n].fd_out && g_global.cmd[n].fd_out[i])
	{
		close(open(g_global.cmd[n].fd_out[i],
				O_WRONLY | O_TRUNC | O_CREAT, 0644));
		i++;
	}
	i = 0;
	while (g_global.cmd[n].fd_out2 && g_global.cmd[n].fd_out2[i])
	{
		close(open(g_global.cmd[n].fd_out2[i],
				O_WRONLY | O_APPEND | O_CREAT, 0644));
		i++;
	}
	if (!g_global.cmd[n].out)
		return (open(g_global.cmd[n].fd_out[ft_pplen(g_global.cmd[n].fd_out)
					- 1], O_WRONLY | O_TRUNC | O_CREAT, 0644));
	return (open(g_global.cmd[n].fd_out2[ft_pplen(g_global.cmd[n].fd_out2)
				- 1], O_WRONLY | O_APPEND | O_CREAT, 0644));
}

int	ft_set_fds(int n)
{
	int	fds[2];

	fds[0] = -2;
	fds[1] = -2;
	if (g_global.cmd[n].in >= 0)
		fds[0] = ft_infile(n);
	if (fds[0] == -1)
		return (1);
	if (g_global.cmd[n].out >= 0)
		fds[1] = ft_outfile(n);
	if (fds[0] >= 0)
	{
		if (g_global.t_stdin < 0)
			g_global.t_stdin = dup(STDIN_FILENO);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	if (fds[1] >= 0)
	{
		if (g_global.t_stdout < 0)
			g_global.t_stdout = dup(STDOUT_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
	}
	return (0);
}

void	ft_reset_fds(void)
{
	if (g_global.t_stdin >= 0)
	{
		dup2(g_global.t_stdin, STDIN_FILENO);
		close(g_global.t_stdin);
		g_global.t_stdin = -1;
	}
	if (g_global.t_stdout >= 0)
	{
		dup2(g_global.t_stdout, STDOUT_FILENO);
		close(g_global.t_stdout);
		g_global.t_stdout = -1;
	}
}
