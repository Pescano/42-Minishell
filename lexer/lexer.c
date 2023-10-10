/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:06:49 by paescano          #+#    #+#             */
/*   Updated: 2023/10/10 17:11:19 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_lexer(void)
{
	g_global.lexer.quotes_state = NO_QUOTES;
	g_global.lexer.pipe_state = 0;
}

int	ft_lexer(char *cmd)
{
	ft_init_lexer();
	if (!ft_check_quotes(cmd))
	{
		printf("%s", ERROR_QUOTES);
		g_global.exit_status = 0;
		return (0);
	}
	if (!ft_check_pipes(cmd))
	{
		printf("%s", ERROR_PIPES);
		g_global.exit_status = 258;
		return (0);
	}
	if (!ft_check_redir(cmd))
	{
		printf("%s", ERROR_REDIR);
		g_global.exit_status = 258;
		return (0);
	}
	return (1);
}
