/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:25:48 by paescano          #+#    #+#             */
/*   Updated: 2023/09/25 13:49:21 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_set_quote_state(char c)
{
	if (c == DOUBLE_QUOTE)
	{
		if (g_global.lexer.quotes_state == NO_QUOTES
			|| g_global.lexer.quotes_state == SINGLE_QUOTE_COMPLETE)
			g_global.lexer.quotes_state = DOUBLE_QUOTE_INCOMPLETE;
		else if (g_global.lexer.quotes_state == DOUBLE_QUOTE_INCOMPLETE)
			g_global.lexer.quotes_state = DOUBLE_QUOTE_COMPLETE;
		else if (g_global.lexer.quotes_state == DOUBLE_QUOTE_COMPLETE)
			g_global.lexer.quotes_state = DOUBLE_QUOTE_INCOMPLETE;
	}
	else if (c == SINGLE_QUOTE)
	{
		if (g_global.lexer.quotes_state == NO_QUOTES
			|| g_global.lexer.quotes_state == DOUBLE_QUOTE_COMPLETE)
			g_global.lexer.quotes_state = SINGLE_QUOTE_IMCOMPLETE;
		else if (g_global.lexer.quotes_state == SINGLE_QUOTE_IMCOMPLETE)
			g_global.lexer.quotes_state = SINGLE_QUOTE_COMPLETE;
		else if (g_global.lexer.quotes_state == SINGLE_QUOTE_COMPLETE)
			g_global.lexer.quotes_state = SINGLE_QUOTE_IMCOMPLETE;
	}
}

int	ft_check_quotes(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		ft_set_quote_state(cmd[i]);
		i++;
	}
	if (g_global.lexer.quotes_state != NO_QUOTES
		&& g_global.lexer.quotes_state != DOUBLE_QUOTE_COMPLETE
		&& g_global.lexer.quotes_state != SINGLE_QUOTE_COMPLETE)
		return (0);
	g_global.lexer.quotes_state = NO_QUOTES;
	return (1);
}
