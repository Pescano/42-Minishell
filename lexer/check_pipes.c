/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:56:12 by paescano          #+#    #+#             */
/*   Updated: 2023/09/27 12:31:12 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_first_pipe(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == SPACES || cmd[i] == TABS)
		i++;
	if (cmd[i] == PIPE)
		return (0);
	return (1);
}

static int	ft_check_last_pipe(char *cmd)
{
	int	i;

	i = ft_strlen(cmd) - 1;
	while (i >= 0 && (cmd[i] == SPACES || cmd[i] == TABS))
		i--;
	if (i >= 0 && cmd[i] == PIPE)
		return (0);
	return (1);
}

int	ft_check_pipes(char *cmd)
{
	int	i;

	if (!ft_check_first_pipe(cmd))
		return (0);
	if (!ft_check_last_pipe(cmd))
		return (0);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == PIPE)
		{
			if (g_global.lexer.pipe_state == 1)
				return (0);
			g_global.lexer.pipe_state = 1;
		}
		else if (cmd[i] != SPACES && cmd[i] != TABS && cmd[i] != PIPE
			&& cmd[i] != LESS && cmd[i] != GREAT)
			g_global.lexer.pipe_state = 0;
		i++;
	}
	return (1);
}
