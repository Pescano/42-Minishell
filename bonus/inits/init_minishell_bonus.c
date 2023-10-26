/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:18:50 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 11:19:07 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
