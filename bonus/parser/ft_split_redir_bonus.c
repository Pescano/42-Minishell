/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_redir_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:02:32 by paescano          #+#    #+#             */
/*   Updated: 2023/10/26 12:02:44 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static char	*ft_split_redin(char *input, int *i)
{
	if (input[*i + 1] == LESS)
	{
		*i += 2;
		return (ft_strdup("<<"));
	}
	*i += 1;
	return (ft_strdup("<"));
}

static char	*ft_split_redout(char *input, int *i)
{
	if (input[*i + 1] == GREAT)
	{
		*i += 2;
		return (ft_strdup(">>"));
	}
	*i += 1;
	return (ft_strdup(">"));
}

char	**ft_split_redir(char *input)
{
	char	**tmp;
	char	*arg;
	int		i;

	i = 0;
	tmp = NULL;
	while (input[i])
	{
		while (input[i] == SPACES)
			i++;
		if (input[i] == '\0')
			break ;
		if (input[i] != LESS && input[i] != GREAT)
			arg = ft_split_normal(input, &i);
		else if (input[i] == LESS)
			arg = ft_split_redin(input, &i);
		else if (input[i] == GREAT)
			arg = ft_split_redout(input, &i);
		tmp = ft_add_pp(arg, tmp);
	}
	return (tmp);
}
