/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:13:44 by paescano          #+#    #+#             */
/*   Updated: 2023/09/25 13:39:25 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_empty_redir(char *str, int *i)
{
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
			*i += 2;
		else
			*i += 1;
	}
	else if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
			*i += 2;
		else
			*i += 1;
	}
	while (str[*i] == ' ' || str[*i] == '\t')
		*i += 1;
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
		return (0);
	return (1);
}

static int	ft_check_last_redir(char *cmd)
{
	int	i;

	i = ft_strlen(cmd) - 1;
	while (i >= 0 && (cmd[i] == ' ' || cmd[i] == '\t'))
		i--;
	if (i >= 0 && (cmd[i] == '<' || cmd[i] == '>'))
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
		if (cmd[i] == '<' || cmd[i] == '>')
		{
			if (!ft_check_empty_redir(cmd, &i))
				return (0);
		}
		i++;
	}
	return (1);
}

// pensar como arreglar el caso de < | echo hola, << | echo hola, etc