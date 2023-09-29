/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:05:08 by paescano          #+#    #+#             */
/*   Updated: 2023/09/29 16:12:18 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_split_redin(char *input, int *i)
{
	if (input[*i + 1] == LESS)
	{
		*i += 2;
		return (ft_strdup("<<"));
	}
	*i += 1;
	return (ft_strdup("<"));
}

char	*ft_split_redout(char *input, int *i)
{
	if (input[*i + 1] == GREAT)
	{
		*i += 2;
		return (ft_strdup(">>"));
	}
	*i += 1;
	return (ft_strdup(">"));
}
