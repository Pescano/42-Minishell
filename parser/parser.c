/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:47:13 by paescano          #+#    #+#             */
/*   Updated: 2023/09/28 19:26:03 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_cmd(char *arg)
{
	char	**tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_pplen(g_global.cmd_splitted) + 1;
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tmp)
		ft_free_error(ERROR_MALLOC);
	tmp[len] = NULL;
	while (i < len - 1)
	{
		tmp[i] = g_global.cmd_splitted[i];
		i++;
	}
	tmp[i] = arg;
	if (g_global.cmd_splitted)
		free((void **)g_global.cmd_splitted);
	g_global.cmd_splitted = tmp;
}

static void	ft_splitcmd(char *input)
{
	char	*arg;
	int		i;

	i = 0;
	g_global.cmd_splitted = NULL;
	while (input[i])
	{
		while (input[i] == SPACES)
			i++;
		if (input[i] == DOUBLE_QUOTE)
			arg = ft_split_quotes(input, &i, DOUBLE_QUOTE);
		else if (input[i] == SINGLE_QUOTE)
			arg = ft_split_quotes(input, &i, SINGLE_QUOTE);
		/*else if (input[i] == LESS)
			arg = ft_split_redin(input, &i);
		else if (input[i] == GREAT)
			arg = ft_split_redout(input, &i);
		else if (input[i] == PIPE)
			arg = ft_split_pipe(input, &i);
		else
			arg = ft_split_normal(input, &i);*/
		else
		{
			arg = ft_strdup("test");
			i++;
		}
		ft_add_cmd(arg);
	}
}

void	ft_parser(char *input)
{
	ft_splitcmd(input);
}
