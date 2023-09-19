/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:12:01 by paescano          #+#    #+#             */
/*   Updated: 2023/09/17 17:19:01 by paescano         ###   ########.fr       */
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
}