/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_vars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:27:35 by paescano          #+#    #+#             */
/*   Updated: 2023/10/16 13:00:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_skip_quote(const char *input, int *i)
{
	(*i)++;
	while (input[*i] && input[*i] != SINGLE_QUOTE)
		(*i)++;
	if (input[*i] == SINGLE_QUOTE)
		(*i)++;
	g_global.lexer.quotes_state = SINGLE_QUOTE_COMPLETE;
}

static char	*ft_dollar_int(char *cmd, int *i)
{
	char	*temp;

	temp = ft_itoa(g_global.exit_status);
	cmd = ft_replace_str(cmd, cmd + *i, cmd + (*i + 2), temp);
	*i += (int)ft_strlen(temp);
	free(temp);
	return (cmd);
}

static char	*ft_dollar_env(char *cmd, int *i)
{
	char	*temp;
	char	*temp2;
	int		j;

	(*i)++;
	j = 0;
	while (cmd[*i + j] && (ft_isalnum(cmd[*i + j]) || cmd[*i + j] == '_'))
		j++;
	temp = ft_substr(cmd, *i, j);
	if (!ft_getenv(temp))
		temp2 = ft_strdup("");
	else
		temp2 = ft_strdup(ft_getenv(temp));
	free(temp);
	cmd = ft_replace_str(cmd, cmd + *i - 1, cmd + (*i + j), temp2);
	*i += (int)ft_strlen(temp2) - 1;
	free(temp2);
	return (cmd);
}

static char	*ft_expand(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		ft_set_quote_state(cmd[i]);
		if (g_global.lexer.quotes_state == SINGLE_QUOTE_IMCOMPLETE)
			ft_skip_quote(cmd, &i);
		if (cmd[i] == '$' && cmd[i + 1] == '?')
			cmd = ft_dollar_int(cmd, &i);
		else if (cmd[i] == '$')
			cmd = ft_dollar_env(cmd, &i);
		else
			i++;
	}
	return (cmd);
}

char	**ft_expand_vars(char **cmd)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (cmd[i])
	{
		if (!ft_strchr(cmd[i], '$'))
			tmp = ft_add_pp(ft_strdup(cmd[i]), tmp);
		else
		{
			g_global.lexer.quotes_state = NO_QUOTES;
			tmp = ft_add_pp(ft_expand(ft_strdup(cmd[i])), tmp);
		}
		i++;
	}
	ft_freevpp((void **)cmd);
	return (tmp);
}
