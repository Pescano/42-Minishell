/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:17:14 by lromero-          #+#    #+#             */
/*   Updated: 2023/10/20 11:27:15 by lromero-         ###   ########.fr       */
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
	int	fd;

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
	int	fd_in;
	int	fd_out;

	fd_in = -2;
	fd_out = -2;
	if (g_global.cmd[0].in >= 0)
		fd_in = ft_infile(0);
	if (fd_in == -1)
		return (1);
	if (g_global.cmd[0].out >= 0)
		fd_out = ft_outfile(0);
	if (fd_in >= 0)
	{
		g_global.t_stdin = dup(STDIN_FILENO);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out >= 0)
	{
		g_global.t_stdout = dup(STDOUT_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
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
