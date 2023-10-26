/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:57:23 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 11:57:40 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_only_space(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != SPACES && cmd[i] != TABS)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_init_lexer(void)
{
	g_global.lexer.quotes_state = NO_QUOTES;
	g_global.lexer.pipe_state = 0;
}

int	ft_lexer(char *cmd)
{
	if (!ft_only_space(cmd))
		return (0);
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
