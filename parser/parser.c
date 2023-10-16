/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:47:13 by paescano          #+#    #+#             */
/*   Updated: 2023/10/16 18:19:50 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_redir(char *str)
{
	size_t	i;
	size_t	len;
	char	current_char;

	i = 0;
	len = strlen(str);
	while (i < len)
	{
		current_char = str[i];
		if (current_char != '<' && current_char != '>'
			&& !(i < len - 1 && current_char == '<' && str[i + 1] == '<')
			&& !(i < len - 1 && current_char == '>' && str[i + 1] == '>'))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_set_up_cmd(void)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (i < g_global.n_cmds)
	{
		tmp = ft_expand_quotes(ft_expand_vars(ft_split_redir(
						g_global.cmd_splitted[i])));
		j = 0;
		while (tmp[j])
		{
			if (ft_is_redir(tmp[j]) && tmp[j][0] != '\0')
			{
				ft_add_redir_cmd(tmp[j], strdup(tmp[j + 1]), i);
				j++;
			}
			else
				g_global.cmd[i].cmds = ft_add_pp(strdup(tmp[j]),
						g_global.cmd[i].cmds);
			j++;
		}
		ft_freevpp((void **)tmp);
		i++;
	}
}

void	ft_parser(char *input)
{
	int	i;

	i = 0;
	ft_split_pipe(input);
	ft_init_cmd();
	ft_set_up_cmd();
	ft_freevpp((void **)g_global.cmd_splitted);
	g_global.cmd_splitted = NULL;
}
