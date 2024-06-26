/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <l.romero.it@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:12:01 by paescano          #+#    #+#             */
/*   Updated: 2023/10/13 17:08:37 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_signals(void)
{
	signal(SIGINT, ft_handler_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_init_minishell(char **env)
{
	ft_init_signals();
	ft_init_env(env);
	g_global.exit_status = 0;
	g_global.t_stdin = -1;
	g_global.t_stdout = -1;
}
