/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:49 by paescano          #+#    #+#             */
/*   Updated: 2023/10/03 12:37:12 by paescano         ###   ########.fr       */
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

static char	*ft_get_input_pipe(char *line, int i)
{
	int		len;

	len = 0;
	while (line[i + len] && line[i + len] != PIPE)
	{
		if ((line[i + len] == DOUBLE_QUOTE)
			&& ft_strchr(&line[i + len + 1], DOUBLE_QUOTE) != NULL)
		{
			len++;
			while (line[i + len] != DOUBLE_QUOTE)
				len++;
		}
		else if ((line[i + len] == SINGLE_QUOTE)
			&& ft_strchr(&line[i + len + 1], SINGLE_QUOTE) != NULL)
		{
			len++;
			while (line[i + len] != SINGLE_QUOTE)
				len++;
		}
		len++;
	}
	return (ft_substr(&line[i], 0, len));
}

void	ft_split_pipe(char *input)
{
	char	*input_pipe;
	int		i;

	i = 0;
	g_global.cmd_splitted = NULL;
	g_global.n_cmds = 0;
	while (input[i])
	{
		input_pipe = ft_get_input_pipe(input, i);
		if (!input_pipe)
			ft_free_error(ERROR_MALLOC);
		g_global.n_cmds++;
		ft_add_cmd(input_pipe);
		i += (int)ft_strlen(input_pipe);
		if (input[i] == PIPE)
			i++;
	}
}
