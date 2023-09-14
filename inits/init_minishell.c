/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:12:01 by paescano          #+#    #+#             */
/*   Updated: 2023/09/14 11:41:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_signals(void)
{
	signal(SIGINT, ft_handler_contrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, ft_handler_contrl_d);
}

void	ft_init_minishell(void)
{
	ft_init_signals();
}
