/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:21:34 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 11:22:05 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_check_empty_redir(char *cmd, int *i)
{
	if (cmd[*i] == LESS)
	{
		if (cmd[*i + 1] == LESS)
			*i += 2;
		else
			*i += 1;
	}
	else if (cmd[*i] == GREAT)
	{
		if (cmd[*i + 1] == GREAT)
			*i += 2;
		else
			*i += 1;
	}
	while (cmd[*i] == SPACES || cmd[*i] == TABS)
		*i += 1;
	if (cmd[*i] == LESS || cmd[*i] == GREAT || cmd[*i] == PIPE)
		return (0);
	return (1);
}

static int	ft_check_last_redir(char *cmd)
{
	int	i;

	i = ft_strlen(cmd) - 1;
	while (i >= 0 && (cmd[i] == SPACES || cmd[i] == TABS))
		i--;
	if (i >= 0 && (cmd[i] == LESS || cmd[i] == GREAT))
		return (0);
	return (1);
}

int	ft_check_redir(char *cmd)
{
	int	i;

	i = 0;
	if (!ft_check_last_redir(cmd))
		return (0);
	while (cmd[i])
	{
		if ((cmd[i] == LESS || cmd[i] == GREAT)
			&& g_global.lexer.quotes_state != DOUBLE_QUOTE_INCOMPLETE
			&& g_global.lexer.quotes_state != SINGLE_QUOTE_IMCOMPLETE)
		{
			if (!ft_check_empty_redir(cmd, &i))
				return (0);
		}
		ft_set_quote_state(cmd[i]);
		i++;
	}
	return (1);
}
