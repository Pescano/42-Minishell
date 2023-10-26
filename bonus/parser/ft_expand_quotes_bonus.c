/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_quotes_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:58:16 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 11:58:31 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static char	*ft_remove(char *cmd, int *i, int j)
{
	char	*temp;

	temp = ft_substr(cmd, *i + 1, j - *i - 1);
	cmd = ft_replace_str(cmd, cmd + *i, cmd + j + 1, temp);
	free(temp);
	*i = j - 1;
	return (cmd);
}

char	*ft_remove_quotes(char *cmd)
{
	int		i;
	int		j;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == DOUBLE_QUOTE)
		{
			j = i + 1;
			while (cmd[j] && cmd[j] != DOUBLE_QUOTE)
				j++;
			cmd = ft_remove(cmd, &i, j);
		}
		else if (cmd[i] == SINGLE_QUOTE)
		{
			j = i + 1;
			while (cmd[j] && cmd[j] != SINGLE_QUOTE)
				j++;
			cmd = ft_remove(cmd, &i, j);
		}
		else
			i++;
	}
	return (cmd);
}

char	**ft_expand_quotes(char **cmd)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (cmd[i])
	{
		if (!ft_strchr(cmd[i], SINGLE_QUOTE)
			&& !ft_strchr(cmd[i], DOUBLE_QUOTE))
			tmp = ft_add_pp(ft_strdup(cmd[i]), tmp);
		else
			tmp = ft_add_pp(ft_remove_quotes(ft_strdup(cmd[i])), tmp);
		i++;
	}
	ft_freevpp((void **)cmd);
	return (tmp);
}
